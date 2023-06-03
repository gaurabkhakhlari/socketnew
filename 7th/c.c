#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<types.h>
int main()
{
	int port=5566;
	char *ip="127.0.0.1";
	int sockfd,newsockfd,clientlen;
	struct sockaddr_in serv_addr,cli_addr;
	char buffer[256];
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("error socket");
		exit(1);
	}
	printf("socket is done");
	memset((char *)&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(ip);
	serv_addr.sin_port = port;
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		perror("error binding");
		exit(1);
	}
	printf("binding is done\n");
        printf("listenning...%d\n",port);
        listen(sockfd,6);
        clientlen= sizeof(cli_addr);
        newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clientlen);
        if(newsockfd < 0)
        {
		perror("error accept");
		exit(1);
		
	}              
	printf("connect with client:\n");
	bzero(buffer,256);
	printf("send to client:");
	fgets(buffer,256,stdin);
	send(newsockfd,buffer,strlen(buffer),0);
	printf("sent done\n");
	bzero(buffer,256);
	recv(newsockfd,buffer,sizeof(buffer),0);
	int num = atoi(buffer);
	printf("number vowel present in the string is: %d\n",num);
	
	close(newsockfd);
	
}
