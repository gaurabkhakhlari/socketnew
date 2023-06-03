#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<ctype.h>


int main()
{
	int port=5566;
	char *ip="127.0.0.1";
	int sockfd;
	struct sockaddr_in serv_addr;
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
		perror("error connect");
		exit(1);
	}
	printf("connected with server\n");
	bzero(buffer,256);
	recv(sockfd,buffer,sizeof(buffer),0);
	printf("server sent:%s\n",buffer);
	char c[256];
	strcpy(c,buffer);
	int vowel=0;
	for(int i=0;i<strlen(c);i++)
	{
		char ch = tolower(c[i]);
		if(ch== 'a' || ch== 'e' || ch== 'i' || ch=='o' || ch=='u')
		{
		vowel++;
                }

	}
	char n[10];
	sprintf(n,"%d",vowel);
	send(sockfd,n,strlen(n),0);
	close(sockfd);
	
	
	
	
}
