#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{

int port=5566;
char *ip="127.0.0.1";
struct sockaddr_in serv_addr,cli_addr;
int sockfd,newsockfd,clientlen;
char buffer[256];
sockfd = socket(AF_INET,SOCK_STREAM,0);
if(sockfd < 0)
{
 
 perror("error socket");
 exit(1);
 

}
printf("socket is done\n");
memset((char *)&serv_addr,0,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr = inet_addr(ip);
serv_addr.sin_port=port;
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0)
{
 perror("error binding");
 exit(1);


}
printf("binding is done\n");
printf("listen----%d\n",port);
listen(sockfd,5);
clientlen = sizeof(cli_addr);
newsockfd = accept (sockfd ,(struct sockaddr *)&cli_addr,&clientlen);
if(newsockfd < 0)
{
 perror("error accepting");
 exit(1);

}
printf("connect with client\n");

bzero(buffer,256);
recv(newsockfd,buffer,sizeof(buffer),0);
int num1=atoi(buffer);
int n1=num1;
printf("client send n1 :%d\n",n1);
recv(newsockfd,buffer,sizeof(buffer),0);
int num2= atoi(buffer);
int n2= num2;
printf("client send n2:%d\n",n2);
int sum=n1+n2;
printf("sum of both number:%d\n",sum);

close (newsockfd);
}
