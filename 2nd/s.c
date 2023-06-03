#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
int main()
{
	int port=8081;
	char *ip="127.0.0.1";
	int sockfd,newsockfd,clientlen,n;
	char buffer[256];
	struct sockaddr_in serv_addr,cli_addr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("error sockfd");
		exit(1);
	}
	printf("[+].socked done\n");
	memset((char *)&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family= AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(ip);
	serv_addr.sin_port = port;

	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0)
	{
		perror("error bindind");
		exit(1);
	}
	printf("[+] bindind is done\n");
	printf("listening port---%d",port);
	listen(sockfd,5);
	clientlen = sizeof(cli_addr);
	newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&clientlen);
	if(newsockfd<0)
	{	

		perror("error accepting");
		exit(1);
	}	
	printf("connected with client\n");
	bzero(buffer,256);
	strcpy(buffer,"what is you name:");
	
	send(newsockfd,buffer,strlen(buffer),0);
	bzero(buffer,256);
	printf("clien sent :");
	recv(newsockfd,buffer,sizeof(buffer),0);
	printf("%s->",buffer);
	
}
