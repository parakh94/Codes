
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


main()
{
	int sockfd ;
	struct sockaddr_in serv_addr;
	int i;
	char buf[100];
/* Opening a socket is exactly similar to the server process */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
		printf("Unable to create socket\n");
		exit(0);
	}
/* Recall that we specified INADDR_ANY when we specified the server
address in the server. Since the client can run on a different
machine, we must specify the IP address of the server.
TO RUN THIS CLIENT, YOU MUST CHANGE THE IP ADDRESS SPECIFIED
BELOW TO THE IP ADDRESS OF THE MACHINE WHERE YOU ARE RUNNING
THE SERVER.
*/
	serv_addr.sin_family= AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(40020);



/* With the information specified in serv_addr, the connect()
system call establishes a connection with the server process.
*/
	if ((connect(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr))) < 0) 
	{
		printf("Unable to connect to server\n");
		exit(0);
	}	
/* After connection, the client can send or receive messages.
However, please note that recv() will block when the
server is not sending and vice versa. Similarly send() will
block when the server is not receiving and vice versa. Fornon-blocking modes, refer to the online man pages.
*/
	while(1){
	for(i=0; i < 100; i++) 
		buf[i] = '\0';
	//read(sockfd, buf, 100);
	//printf("%s\n", buf);
	printf("Enter the message:");
	fgets(buf,100,stdin);
	int len=strlen(buf);
	buf[len-1]='\0';
	write(sockfd, buf, strlen(buf) + 1);
	for(i=0; i < 100; i++) 
		buf[i] = '\0';
	read(sockfd, buf, 100);
	printf("Message from server:");
	printf("%s\n", buf);
	
	}
	close(sockfd);
}



