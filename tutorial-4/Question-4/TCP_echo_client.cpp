#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>   
#include <arpa/inet.h>
#include <string.h>
using namespace std;

int SERV_PORT=9000;
char* SERV_HOST_ADDR = "127.0.0.1";

int main(int argc, char **argv)
{
int sockfd, n;
struct sockaddr_in servaddr;
char sendline[500], recvline[500];

if (argc != 2)
	printf("usage: tcpcli <IPaddress>");

sockfd = socket(AF_INET, SOCK_STREAM, 0);
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
servaddr.sin_port = htons(SERV_PORT);

connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

fgets(sendline, 512, stdin);
n = strlen(sendline);
write(sockfd, sendline, n);

n = read(sockfd, recvline, 512);
if (n < 0) 
	printf("Read Error\n");

recvline[n] = 0;
fputs(recvline, stdout);
exit(0);

}