from exam_protocol_pb2 import BRD_ctrl as Adc_msg
from socket import socket, AF_INET, SOCK_DGRAM
import signal

if __name__ == '__main__':
    signal.signal(signal.SIGINT, signal.SIG_DFL)
    sock = socket(AF_INET, SOCK_DGRAM)
    sock.bind(("0.0.0.0", 9009))
    ex = False
    while not ex:
        data, addr = sock.recvfrom(1024)
        pkt = Adc_msg()
        pkt.ParseFromString(data)
        print(f"cmd: {pkt.command}, out:{pkt.out}, status:{pkt.status}")
        if pkt.command == 11:
            ex = True
