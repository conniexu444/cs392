#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>

#define BUFLEN 512	//Max length of buffer
#define PORT 1025	//The port on which to listen for incoming data


void errexit(char *s)
{
	perror(s);
	exit(1);
}

int main(void)
{
	struct sockaddr_in si_me, si_other;
	
	int s, i, slen = sizeof(si_other) , recv_len;
	char buf[BUFLEN];
	
	//create a UDP socket
	if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		errexit("socket");
	}
	
	// zero out the structure
	memset((char *)&si_me, 0, sizeof(si_me));
	
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(PORT);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//bind socket to port
	if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
	{
		errexit("bind");
	}
	
	//keep listening for data
	while(1)
	{
		fflush(stdout);
		
		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen)) == -1)
		{
			errexit("recvfrom()");
		}

			//print details of the client/peer and the data received
		
		//now reply the client with the same data
		if (sendto(s, buf, recv_len, 0, (struct sockaddr*)&si_other, slen) == -1)
		{
			errexit("sendto()");
		}

		if(memcmp(buf, "exit", 4) == 0){
			close(s);
			exit(1);
		}

	}

	close(s);
	return 0;
}
