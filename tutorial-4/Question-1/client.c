#include"stdio.h"  
#include"stdlib.h"  
#include"sys/types.h"  
#include"sys/socket.h"  
#include"string.h"  
#include"netinet/in.h"  
#include"netdb.h"
#include <arpa/inet.h>
  
#define PORT 4444 
#define BUF_SIZE 2000 
  
int main(int argc, char**argv) {  
 struct sockaddr_in addr, cl_addr;  
 int sockfd, ret;  
 char buffer[BUF_SIZE];  
 struct hostent * server;
 char * serverAddr;

 if (argc < 2) {
  exit(1);  
 }

 serverAddr = argv[1]; 
 
 sockfd = socket(AF_INET, SOCK_STREAM, 0);  
 addr.sin_family = AF_INET;  
 addr.sin_addr.s_addr = inet_addr(serverAddr);
 addr.sin_port = PORT;     

 ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));  

 while (fgets(buffer, BUF_SIZE, stdin) != NULL) {

  ret = sendto(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &addr, sizeof(addr));  
  ret = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);  
   
   printf("Upper Case: ");
   fputs(buffer, stdout);
   printf("\n");
  
 }
 
 return 0;    
}  