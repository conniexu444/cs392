
/*
Constance Xu
I pledge my honor that I have abided by the Stevens Honor System.
 * You are required to implement a function
 * 	int udp_msg_client(char *ip, int port, char * message, char *buf, int *buflen);
 *	
 *	In this function, you will need to create a socket for UDP communication with a remote server
 *		IP address of the server is specified in argument "ip"; hint regarding how to convert a string IP to an integer IP is given
 *		PORT number of the server is given in argument "port"
 *		The message to send to the server is specified in the argument "message"; length of the message equals to the size of the string in "message"
 *		After you send data to the server, you will need to receive a reply from the server, and you are required to keep that piece of data in the argument buffer "buf"; Original size of the buffer is specified in the integer pointed to by "buflen" (to get the size, you need to dereference the pointer); You can assume "buf" is large enough to keep the data from the server;
 *		Note that you have to init "buf" with all zeros before you read data from the server to "buf"
 *
 *		After you receive the data from the server, you need to update the integer in "buflen" with the number of bytes being received.
 *
 * 		In UDP communication, you do not need to connect to the server; instead, you can simply send data to the server and then wait for reply. Hints regarding this is given as comments below
 *
 *Note all the header files have been provided. You do not need to add more. But if you want, that's fine
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>

#define SERVER "127.0.0.1"
#define BUFLEN 512	//Max length of buffer
#define PORT 1025	//The port on which to send data


//Please implement your code below
int udp_msg_client(char *ip, int port, char * message, char *buf, int *buflen){

	/*Hint 1: data structure to keep address of the server*/
	struct sockaddr_in si_other;
	int si_len = sizeof(si_other); //gets length

	/*Hint 2: how to create a socket for UDP communication */
	int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	//... some code here to init si_other
	memset(&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_addr.s_addr = htonl(INADDR_ANY);
	si_other.sin_port = htons(port);

	/*Hint 3: some code to convert IP address and save the result in si_other*/
	inet_aton(ip, &si_other.sin_addr); 

	/*hint 4: API to send data to a UDP server without connection: ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen); */ //You may want to google or man it to find how to us it (the "flags" argument can be 0)

	/*hint 5: how to set the "const struct sockaddr *dest_addr" in sendto */
	//sendto(.., ..., ..., ..., (struct sockaddr *)&si_other, ...); //"..." indicates one argument that you will nee to set up 
	//... some code to do sendto
	int lenmessage = strlen(message);
	if (sendto(s, message, lenmessage, 0, (struct sockaddr *) &si_other, si_len) == -1) {
		close(s);
		perror("Error: Cannot send to server\n");
		exit(1);
	}

	//... some code to init buf with all zeros
	for (int i = 0; i < *buflen; i++) {
		buf[i] = 0;
	}

	/*hint 6: API to receive data from a UDP server without connection: ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);*/ //You may want to google or man it to find how to us it (the "flags" argument can be 0)

	/*hint 7: how to set the "const struct sockaddr *src_addr" in recvfrom --- similar to sendto*/

	//... some code to do recvfrom
	//Do not forget to update "buflen" with return value of recvfrom
	int b;
	if ((b = recvfrom(s, buf, *buflen, 0, (struct sockaddr *) &si_other, &si_len)) == -1) {
		close(s);
		perror("Error: cound not receive this from the server\n");
		exit(1);
	}
	 buflen = &b;

	//do no forget to close the socket of the client
	close(s);
}


int main(void)
{
	char buf[BUFLEN];
	int bufsz = BUFLEN;

	printf("Test case 1:\n");
	printf("The data you send is ==== %s\n", "First test case for udp server");

	udp_msg_client(SERVER, PORT, "First test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "First test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");

	bufsz = BUFLEN;
	printf("Test case 2:\n");
	printf("The data you send is ==== %s\n", "Second test case for udp server");

	udp_msg_client(SERVER, PORT, "Second test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "Second test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");

	bufsz = BUFLEN;
	printf("Test case 3:\n");
	printf("The data you send is ==== %s\n", "Third test case for udp server");

	udp_msg_client(SERVER, PORT, "Third test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "Third test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");


	bufsz = BUFLEN;
	printf("Test case 4:\n");
	printf("The data you send is ==== %s\n", "Fourth test case for udp server");

	udp_msg_client(SERVER, PORT, "Fourth test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "Fourth test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");


	bufsz = BUFLEN;
	printf("Test case 5:\n");
	printf("The data you send is ==== %s\n", "Fifth test case for udp server");

	udp_msg_client(SERVER, PORT, "Fifth test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "Fifth test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");



	udp_msg_client(SERVER, PORT, "exit", buf, &bufsz);

	return 0;
}
