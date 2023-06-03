#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int fact(int n)
{
	if(n==0 && n==1)
	{
	return 1;
	}
	return n*fact(n-1);

}
int main()
{

 int port = 8080;
 char *ip = "127.0.0.1";
 struct sockaddr_in serv_addr,cli_addr;
 int sockfd,newsockfd,clientlen,n;
 char buffer[256];
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 if(sockfd < 0)
 {
	perror("error socket");
	exit(1);

 }
 printf("[+].socket is done\n");
 memset((char *)&serv_addr,0,sizeof(serv_addr));
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = inet_addr(ip);
 serv_addr.sin_port = port;
 if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
 {
	perror("error in binding");
	exit(1);
 }
 printf("bindinding is done\n");
 printf("listen --->%d",port);
 listen(sockfd,5);
 clientlen=sizeof(cli_addr);
 newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&clientlen);
 if(newsockfd < 0)
 {
 	perror("error accept");
 	exit(1);
 
 
 }
 printf("connected with client\n");
 bzero(buffer,256);
 printf("enter a number:");
 fgets(buffer,256,stdin);
 send(newsockfd,buffer,strlen(buffer),0);
 
 close(newsockfd);
 
 
 
 
 
 
}
