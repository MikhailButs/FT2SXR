from core.core import Core
from socket import socket, AF_INET, SOCK_DGRAM, SOL_SOCKET, SO_BROADCAST
from threading import Thread, Lock
from socket import error as sock_error
from time import time
from datetime import datetime


class NetManagerBase(Core):
    def __init__(self, parent=None, ip="0.0.0.0", port=22222, name='NetManager', alive: float = None):
        super().__init__(parent, port)

        self.port = port
        self.sock = socket(AF_INET, SOCK_DGRAM)
        self.sock.bind((ip, port))
        self.sock.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
        self.ip = self.sock.getsockname()[0]
        self.name = name
        self.clients = dict()
        self.alive = alive
        self.lock = Lock()
        self.actv = True
        self.thrd = Thread(name=f'Thread-{self.name}', target=self.run, daemon=True)
        self.thrd.start()

    def run(self):
        pass

    def channel0_slot(self, data: bytes):
        self.send_to_clients(data)

    def broadcast(self, data):
        if self.ip != "0.0.0.0":
            ip = self.ip[:self.ip.rfind('.') + 1] + "255"
            n = self.sock.sendto(data, (ip, self.port))
            return n
        else:
            return None

    def send_to_clients(self, data: bytes):
        # remove old connections
        if self.alive is not None:

            clients = self.clients.copy()
            for addr in self.clients:
                if time()-self.clients[addr] > self.alive:
                    clients.pop(addr)

            self.lock.acquire()
            self.clients = clients
            self.lock.release()

        for addr in self.clients:
            self.sock.sendto(data, addr)

    def timerEvent(self, a0: 'QTimerEvent') -> None:
        self.response.data = f'{self.ip}:{self.port} {self.name} alive at {datetime.fromtimestamp(time())}'.encode()
        if self.response.IsInitialized():
            self.channel0.emit(self.response.SerializeToString())
            self.broadcast(self.response.SerializeToString())


class NetManagerSimple(NetManagerBase):
    """
    Class only receive from socket and send data to signal system
    """

    def __init__(self, parent=None, ip="0.0.0.0", port=9009, alive: float = None, channel=1):
        super().__init__(parent, ip, port, 'NetManager-Simple', alive)
        core = self.get_origin_core()
        if core is not None:
            exec(f'self.channel0.connect(core.channel{channel:1})')

    def run(self):
        while self.actv:
            try:
                data, addr = self.sock.recvfrom(1024)

                if addr != (self.ip, self.port):
                    if self.parent is not None and len(data) > 0:
                        self.channel0.emit(data)

            except sock_error:
                pass

    def channel0_slot(self, data: bytes):
        pass


class NetManager(NetManagerBase):
    """
    Class for send/receive channels data through socket
    """

    def __init__(self, parent=None, ip="0.0.0.0", port=22222, alive: float = None,  channel=0):
        super().__init__(parent, ip, port, 'NetManager-ch0', alive)
        core = self.get_origin_core()
        if core is not None:
            exec(f'self.channel0.connect(core.channel{channel:1})')
            exec(f'core.channel{channel:1}.connect(self.channel0_slot)')
        self.not_reflected = set()

    def run(self):
        while self.actv:
            try:
                data, addr = self.sock.recvfrom(1024)
                if addr != (self.ip, self.port):  # here we reject loopback
                    self.lock.acquire()
                    self.clients[addr] = time()

                    self.lock.release()

                    if self.parent is not None and len(data) > 0:
                        # we await reflection from core so store all data from socket in set before sending to channel
                        self.lock.acquire()
                        self.not_reflected.add(data)
                        self.lock.release()
                        self.channel0.emit(data)
            except sock_error:
                pass

    def channel0_slot(self, data: bytes):
        # catch reflection
        if data in self.not_reflected:
            self.lock.acquire()
            self.not_reflected.remove(data)
            self.lock.release()
        # all other data resend to clients
        else:
            self.send_to_clients(data)
