#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>


#define LINE_SIZE 240
int main(int argc,char *argv[])
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	struct hostent *host; 
	char *r;
	char temp[LINE_SIZE],temp2[LINE_SIZE];
	int ret;
	FILE *f;
	char *ptr;
	
	if(argc!=4)
	{
		printf("sendmail {smtp_server} {from} {to}\n");
		printf("mail subject and content will get from /var/mail_content.txt\n");
		return 0;
	}
	host=gethostbyname(argv[1]);
	if(host==NULL) { 
		printf("gethostbyname error\n");
		return -1;
	} 
	
	
	ptr=strstr(argv[3],"@");	
	ptr++;
	
		
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	memset(&address,0,sizeof(address));
	address.sin_family=PF_INET;
	address.sin_addr=*((struct in_addr *)host->h_addr); 
	address.sin_port=htons(25);
	len=sizeof(address);
	
	ret=connect(sockfd,(struct sockaddr *)&address,len);
	if(ret==-1)
	{
		printf("error\n");
		return -1;	
	}
	
	
	read(sockfd,temp,LINE_SIZE);
	//printf("%s\n",temp);
	sprintf(temp,"HELO %s\r\n",ptr);
	write(sockfd,temp,strlen(temp));
	read(sockfd,temp,LINE_SIZE);
	//printf("%s\n",temp);
	sprintf(temp,"MAIL FROM: %s\r\n",argv[2]);
	write(sockfd,temp,strlen(temp));
	read(sockfd,temp,LINE_SIZE);
	//printf("%s\n",temp);
	
	sprintf(temp,"RCPT TO: %s\r\n",argv[3]);
	write(sockfd,temp,strlen(temp));
	read(sockfd,temp,LINE_SIZE);
	//printf("%s\n",temp);
	
	
	sprintf(temp,"DATA\r\n");
	write(sockfd,temp,strlen(temp));		
	sprintf(temp,"To: <%s>\r\n",argv[3]);
	write(sockfd,temp,strlen(temp));

		
		
	f=fopen("/var/mail_content.txt","r");
	
	
	r=fgets(temp2,LINE_SIZE,f);			
	if(r!=NULL)
	{	
		sprintf(temp,"Subject: %s\r\n",temp2);
		write(sockfd,temp,strlen(temp));
	
		while(1)
		{

			r=fgets(temp,LINE_SIZE,f);			
			if(r==NULL) break;
			sprintf(temp,"%s",temp);
			write(sockfd,temp,strlen(temp));
			if(feof(f)) break;			
		}
	}
			
	fclose(f);
	
	sprintf(temp,"\r\n.\r\n");
	write(sockfd,temp,strlen(temp));			
	read(sockfd,temp,LINE_SIZE);
	//printf("%s\n",temp);
	
	sprintf(temp,"QUIT\r\n");
	write(sockfd,temp,strlen(temp));		
	
	close(sockfd);
	return 0;
}
