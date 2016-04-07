
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
/* The following three files must be included for network programming */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
/* THE SERVER PROCESS */
/* Compile this program with cc server.c -o server
and then execute it as ./server &
*/
main()
{
	int sockfd, newsockfd ; /* Socket descriptors */
	int clilen;
	struct sockaddr_in cli_addr, serv_addr;
	int i;
	char buf[100];
/* We will use this buffer for communication */
/* The following system call opens a socket. The first parameter
indicates the family of the protocol to be followed. For internet
protocols we use AF_INET. For TCP sockets the second parameter
is SOCK_STREAM. The third parameter is set to 0 for user
applications.
*/
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
		printf("Cannot create socket\n");
		exit(0);
	}
/* The structure "sockaddr_in" is defined in <netinet/in.h> for the
internet family of protocols. This has three main fields. The
field "sin_family" specifies the family and is therefore AF_INET
for the internet family. The field "sin_addr" specifies the
internet address of the server. This field is set to INADDR_ANY
for machines having a single IP address. The field "sin_port"
specifies the port number of the server.
*/
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(40020);

	memset(serv_addr.sin_zero, '\0', sizeof (serv_addr.sin_zero));
	
/* With the information provided in serv_addr, we associate the server
with its port using the bind() system call.
*/
	if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
	{
		printf("Unable to bind local address\n");
		exit(0);
	}
	listen(sockfd, 5); /* This specifies that up to 5 concurrent client
requests will be queued up while the system is
executing the "accept" system call below.
*/
/* In this program we are illustrating an iterative server -- one
which handles client connections one by one.i.e., no concurrency.
The accept() system call returns a new socket descriptor
which is used for communication with the server. After the
communication is over, the process comes back to wait again on
the original socket descriptor.
*/
	while (1) 
	{
/* The accept() system call accepts a client connection.
It blocks the server until a client request comes.
The accept() system call fills up the client's details
in a struct sockaddr which is passed as a parameter.
The length of the structure is noted in clilen. Note
that the new socket descriptor returned by the accept()
system call is stored in "newsockfd".
*/
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,&clilen) ;
		if (newsockfd < 0)
		{
			printf("Accept error\n");
			exit(0);
		}
/* We initialize the buffer, copy the message to it,
and send the message to the client.
*/
		//strcpy(buf,"Message from server");
		while(1){
		for(i=0; i < 100; i++) 
			buf[i] = '\0';
		read(newsockfd, buf, 100);
		printf("Message from client:");
/* We again initialize the buffer, and receive a
message from the client.
*/
		//for(i=0; i < 100; i++) 
			//buf[i] = '\0';
		//recv(newsockfd, buf, 100, 0);
		printf("%s\n", buf);
		for(i=0; i < 100; i++) 
			buf[i] = '\0';
		printf("Enter the message:");
		fgets(buf,100,stdin);
		int len=strlen(buf);
		buf[len-1]='\0';
		write(newsockfd, buf, strlen(buf) + 1);
		}
		close(newsockfd);
	}
	
}



