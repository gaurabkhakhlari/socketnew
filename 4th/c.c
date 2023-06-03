#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int fact(int n)
{
	if(n==0 || n==1)
	{
	return 1;
	}
	return n * fact(n-1);

}
int main()
{

 int port = 8080;
 char *ip = "127.0.0.1";
 struct sockaddr_in serv_addr;
 int sockfd;
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
 if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
 {
 	perror("error connect");
 	exit(1);
 }
 printf("conneted with server \n");
 bzero(buffer,256);
 recv(sockfd,buffer,sizeof(buffer),0);
 int num = atoi(buffer);
 int f=fact(num);
 printf("the number is \n%d \n%d\n",num,f);
 close(sockfd);
 
 
 
 
 
 
 
}
