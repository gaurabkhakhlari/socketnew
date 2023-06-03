#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
int main()
{
	int port=8082;
	char *ip="127.0.0.1";
	int sockfd,newsockfd,clientlen,n;
	struct sockaddr_in serv_addr,cli_addr;
	char buffer[256];
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("error socket");
		exit(1);
	}
	printf("[+] socket connected\n");
	memset((char *)&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(ip);
	serv_addr.sin_port=port;

	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) <  0)
	{
		perror("error bind");
		exit(1);
	}
	printf("[+] bindind is done \n");
	printf("lisenting.... port %d\n",port);
        listen(sockfd,5);
	clientlen=sizeof(cli_addr);
	newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clientlen);
	
	bzero(buffer,256);
	recv(newsockfd,buffer,sizeof(buffer),0);
	printf("recived form client: %s",buffer);
	int num = atoi(buffer);
	for(int i=0;i<num;i++)
	{
		printf("hello world\n");

	}
	printf("send to client..");
	bzero(buffer,256);
	fgets(buffer,256,stdin);
	send(newsockfd,buffer,strlen(buffer),0);
	close(newsockfd);
	
}
