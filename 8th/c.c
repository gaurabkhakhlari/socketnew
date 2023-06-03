#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
	int port=8081;
	char *ip="127.0.0.1";
	int sockfd;
	struct sockaddr_in serv_addr;
	char buffer[256];
	sockfd= socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("error socket");
		exit(1);
		
	}
	printf("socket is done\n");
	memset((char *)&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(ip);
	serv_addr.sin_port = port;
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
	{
	 perror("error connect");
	 exit(1);
	 
	}
	printf("connected with server\n");
	bzero(buffer,256);
	printf("enter some things:");
	fgets(buffer,256,stdin);
	send(sockfd,buffer,strlen(buffer),0);
	
	bzero(buffer,256);
	recv(sockfd,buffer,sizeof(buffer),0);
	printf("%s\n",buffer);
	bzero(buffer,256);
	printf("enter a number:");
	fgets(buffer,256,stdin);
	send(sockfd,buffer,strlen(buffer),0);
        	
}
