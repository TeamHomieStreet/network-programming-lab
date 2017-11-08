#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"sys/socket.h"
#include"string.h"
#include"netinet/in.h"
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 4444
#define BUF_SIZE 2000
#define CLADDR_LEN 100

void main() {
 struct sockaddr_in addr, cl_addr;
 int sockfd, len, ret, newsockfd;
 char buffer[BUF_SIZE];
 pid_t childpid;
 char clientAddr[CLADDR_LEN];
 
 sockfd = socket(AF_INET, SOCK_STREAM, 0);

 addr.sin_family = AF_INET;
 addr.sin_addr.s_addr = INADDR_ANY;
 addr.sin_port = PORT;
 

 // printf("%d\n",ret);
 ret = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));

 // printf("%d\n",ret);
 listen(sockfd, 5);
 for (;;) { 
  len = sizeof(cl_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cl_addr, &len);


  inet_ntop(AF_INET, &(cl_addr.sin_addr), clientAddr, CLADDR_LEN);
  if ((childpid = fork()) == 0) { 

  close(sockfd); 

   for (;;) {
    memset(buffer, 0, BUF_SIZE);
    ret = recvfrom(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &cl_addr, &len);
   	
    printf("Received data from %s: %s %d\n", clientAddr, buffer, ret); 
	buffer[ret] = '\0';
    for(int i=0;i<ret && buffer[i+1]!='\0';i++){
    	buffer[i] -= 32;
    }
    ret = sendto(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &cl_addr, len);   

    printf("Sent data to %s: %s\n", clientAddr, buffer);
   }
  }
  close(newsockfd);
 }
}