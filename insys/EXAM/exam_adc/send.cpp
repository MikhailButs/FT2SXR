#include <stdio.h>
#include "exam_protocol.pb.h"
#include <unistd.h>
#include <sys/types.h>

#ifdef __IPC_LINUX__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SNDPORT 9009
#define EXIT_CODE 0
#else
#define EXIT_CODE 0
#endif


int main(){
#ifdef __IPC_LINUX__
	int sock;
	struct sockaddr_in addr;
	sock = socket(AF_INET, SOCK_DGRAM, 0);

	if(sock < 0)
	{
		return -1;
	}

	int optval = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) <0)
	{
		return -1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(SNDPORT);
	inet_aton("192.168.0.255", &addr.sin_addr);
#endif

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	exam_proto::BRD_ctrl pkt;

	printf("ByteSizeLong %d\n", pkt.ByteSizeLong());
	printf("IsInitialized %d\n", pkt.IsInitialized());
	pkt.set_command(0);
	pkt.set_out(0);
	pkt.set_status(0);
	int pktSize = pkt.ByteSizeLong();
	char data[pktSize];

	int i = 0;
	char ex[10];
	do
	{
		scanf("%s", ex);
		if(strcmp(ex, "exit") != EXIT_CODE)
			pkt.set_command(0);
		else
			pkt.set_command(11);

		pkt.set_out(i);
		pkt.set_status(-1);
		pkt.SerializeToArray(data, pktSize);
		printf("cmd: %d, out: %d, status: %d\n", pkt.command(), pkt.out(), pkt.status());
		printf("string byte length: %d\n", sizeof(data));
		printf("ByteSizeLong %d\n", pkt.ByteSizeLong());

	    for(int j = 0; j < pktSize; j++)
        	printf("\\x%02x", data[j]);
		printf("\n");
#ifdef __IPC_LINUX__
		sendto(sock, data, sizeof(data), 0,
			   (struct sockaddr *)&addr, sizeof(addr));
#endif
		i++;
	}while(strcmp(ex, "exit") != EXIT_CODE);

#ifdef __IPC_LINUX__
	close(sock);
#endif

	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}