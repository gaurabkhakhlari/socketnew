#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int p(char str[])
{
 int i = 0;
 int h = strlen(str)-1;
 while(h > 1)
 {
   if (str[i++] == str[h--])
   { 
    return 1;
   }
   
 }
return 0;
}
int main()
{
int port=8081;
char *ip="127.0.0.1";
int sockfd,newsockfd,clientlen;
struct sockaddr_in serv_addr,cli_addr;
char buffer[256];

sockfd = socket(AF_INET,SOCK_STREAM,0);
if (sockfd < 0)
{
	perror("error socket");
	exit(1);
}
printf("socket is done\n");
memset((char *)&serv_addr,0,sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = inet_addr(ip);
serv_addr.sin_port = port;
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
{
	perror("error binding");
	exit(1);

} 
printf("binding is done \n");
printf("listen... port----%d\n",port);
listen(sockfd,6);
clientlen = sizeof(cli_addr);
newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&clientlen);
if (newsockfd < 0 )
{
	perror("error accept");
	exit(1);

}
printf("connect with client");
bzero(buffer,256);
recv(newsockfd,buffer,sizeof(buffer),0);
printf("client sent :%s\n",buffer);
buffer[strcspn(buffer,"\n")] = '\0';
int pali = p(buffer);
if(pali)
{
  char c[]="yes";
  send(newsockfd,c,strlen(c),0);
}
else
{
 char c[]="no";
 send(newsockfd,c,strlen(c),0);
}
printf("sent to client %s\n",pali ? "yes" : "no");

close(newsockfd);
close(sockfd);






}

