#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
int main()
{
	int port=8081;
	char *ip="127.0.0.1";
	int sockfd,n;
	char buffer[256];
	struct sockaddr_in serv_addr;
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
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0)
	{
		perror("errror connecting");
		exit(1);
	}
	printf("connected with server\n");
	bzero(buffer,256);
	recv(sockfd,buffer,sizeof(buffer),0);
	printf("%s",buffer);
	bzero(buffer,256);
	fgets(buffer,256,stdin);
	send(sockfd,buffer,strlen(buffer),0);
	
	
}
