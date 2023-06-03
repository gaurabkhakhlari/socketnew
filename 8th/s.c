#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
	int port=8081;
	char *ip="127.0.0.1";
	int sockfd,newsockfd,clientlen;
	struct sockaddr_in serv_addr,cli_addr;
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
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
	{
		perror("error bind");
		exit(1);
	}
	printf("binding is done\n");
	printf("listening---%d\n",port);
	listen(sockfd,5);
	clientlen=sizeof(cli_addr);
	newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&clientlen);
	if(newsockfd < 0)
	{

         perror("error accept");
         exit(1);

        }
        printf("connect with client\n");
	bzero(buffer,256);
	recv(newsockfd,buffer,sizeof(buffer),0);
        printf("send by client :%s",buffer);
        char c[256];
        strcpy(c,buffer);
        bzero(buffer,256);
        strcpy(buffer,"recvied");
        send(newsockfd,buffer,strlen(buffer),0);
        bzero(buffer,256);
        recv(newsockfd,buffer,sizeof(buffer),0);
        int n = atoi(buffer);		
        for(int i=0;i<n;i++)
        {

		printf("%s\n",c);

	}
	close(newsockfd);
}
