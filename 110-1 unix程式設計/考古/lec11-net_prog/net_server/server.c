/*******************************************************************************
 *
 * The server side of the network server demo program
 *
 ******************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
#include <string.h>

main ()
{
	struct sockaddr_in myaddr;
	struct sockaddr_in client_addr;
	int sockfd;
	int streamfd;
	char str_buf[100];
	int port;
	int status;
	int addr_size;

	//setup my address
	bzero (&myaddr, sizeof(myaddr));
	myaddr.sin_family = PF_INET;
	myaddr.sin_port = 5555;
	myaddr.sin_addr.s_addr = inet_addr ("127.0.0.1");

	//create a socket for the local address 127.0.0.1
	sockfd = socket (PF_INET, SOCK_STREAM, 0);
	bind (sockfd, (struct sockaddr *) &myaddr, sizeof(struct sockaddr_in));

	//wait for a client to connect
	listen (sockfd, 10);
	addr_size = sizeof (client_addr);
	streamfd = accept (sockfd, (struct sockaddr *) &client_addr, &addr_size);

	status = read (streamfd, str_buf, 100);
	printf ("string from net: %s\n", str_buf);

	return 0;
}//main ()



















