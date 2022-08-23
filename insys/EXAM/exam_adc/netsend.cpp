#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include "netsend.h"
#include "exam_protocol.pb.h"


//using namespace std;

#define SNDPORT 9009

int netsend(ULONG cmd, ULONG out, S32 status)
{
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
//	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
//	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_aton("192.168.0.255", &addr.sin_addr);
	//addr.sin_addr.s_addr = inet_addr("192.168.0.255");

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	exam_proto::BRD_ctrl pkt;

	pkt.set_command(cmd);
	pkt.set_out(out);
	pkt.set_status(status);
	if(pkt.IsInitialized())
	{
		int pktSize = pkt.ByteSizeLong();
		char data[pktSize];
		pkt.SerializeToArray(data, pktSize);
		sendto(sock, data, sizeof(data), 0,
		   (struct sockaddr *)&addr, sizeof(addr));
	}
	close(sock);
	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}