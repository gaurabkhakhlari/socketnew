#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
 int port = 8081;
 char *ip = "127.0.0.1";
 int sockfd,newsockfd,clientlen,n;
 struct sockaddr_in serv_addr,cli_addr;
 char buffer[256];
 sockfd = socket(AF_INET,SOCK_STREAM,0);
 if(sockfd < 0)
 {
 	perror("error socketing");
 	exit(1);
 }
 printf("socketing is done\n");
 memset((char *)&serv_addr,0,sizeof(serv_addr));
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = inet_addr(ip);
 serv_addr.sin_port = port;
 if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
 {
	perror("errro binding");
	exit(1);

 }
 	printf("binding is done\n");
 	

	listen(sockfd,5);
        clientlen=sizeof(cli_addr);
        newsockfd= accept(sockfd,(struct sockaddr *)&cli_addr,&clientlen);
        if(newsockfd < 0)
        {
		perror("error accepting");
		exit(1);
	}
	printf("connected with client\n");
	
	bzero(buffer,256);
	strcpy(buffer,"what is your DOB year:");
	send(newsockfd,buffer,strlen(buffer),0);
	
	bzero(buffer,256);
	recv(newsockfd,buffer,sizeof(buffer),0);
	printf("dob year clien:%s",buffer);
	int c=atoi(buffer);
	int p=2023;
	int d=p-c;
	char age[10];
	sprintf(age,"%d",d);
	send(newsockfd,age,strlen(age),0);
	printf("done!!!\n");
	
	
}
