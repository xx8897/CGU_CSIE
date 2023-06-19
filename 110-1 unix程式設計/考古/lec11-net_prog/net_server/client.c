/*******************************************************************************
 *
 * The client side of the network server demo program
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
	struct sockaddr_in server_addr;
	int sockfd;
	int status;

	//setup the server address
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = 5555;
	server_addr.sin_addr.s_addr = inet_addr ("127.0.0.1");

	//connect to the server
	sockfd = socket (PF_INET, SOCK_STREAM, 0);
	connect (sockfd, (struct sockaddr *) &server_addr,
		sizeof(struct sockaddr_in));

	//send a string to the server
	status = write (sockfd, "Hello!", strlen("Hello")+1);

	return 0;
}//main ()



















