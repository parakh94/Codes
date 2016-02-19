/*Parakh Bansal(13/CS/70)
Antarin Karmakar(13/CS/89)*/


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
	int i,p,l;
	char buf[100];

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
		printf("Unable to create socket\n");
		exit(0);
	}

	serv_addr.sin_family= AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(50018);

	for(i=0; i < 100; i++) 
		buf[i] = '\0';


	if ((connect(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr))) < 0) 
	{
		printf("Unable to connect to server\n");
		exit(0);
	}

	while(1)
	{
		printf("Enter the expression:");
		scanf("%s",buf);
		
		l=0;
		while(l<strlen(buf))
		{
			printf("Sending to server\n***********************\n");
			p=send(sockfd, buf, strlen(buf) + 1, 0);
			if(p<0)
			{
				printf("Error in sending to server\n");
				exit(0);
			}
			l = l + p;
				
		}
		l=0;
		while(l<strlen(buf))
		{
			printf("Recieving from server\n*********\n");
			p=recv(sockfd, buf, 100, 0);
			if(p<0)
			{
				printf("Error in reciving from server\n");
				exit(0);
			}
			l = l + p;
		}
			
		if(strcmp(buf,"exit")==0)
		{
			printf("Exit from client....\n"); 			
			exit(0);
		}	
	
		printf("Value recieved from the server:");
		printf("%s\n",buf);
		printf("**********************\n");
	}
	close(sockfd);
	
}
