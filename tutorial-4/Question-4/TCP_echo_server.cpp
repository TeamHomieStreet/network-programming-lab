#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>   
#include <unistd.h>
using namespace std;

int SERV_PORT = 9000;

int main(int argc, char **argv)
{

int listenfd, connfd;
struct sockaddr_in servaddr, cliaddr;
int  childpid, n;
socklen_t clilen;
char line[500];

listenfd = socket(AF_INET, SOCK_STREAM, 0);
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(SERV_PORT);
bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
listen(listenfd, 5);

for ( ; ; ) {
	clilen = sizeof(cliaddr);
	connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
	if ( (childpid = fork()) == 0) { /* child process */
		close(listenfd); /* close listening socket */
		n = read(connfd, line, 512);
		write(connfd, line, n);
		fputs(line, stdout);
		close(connfd);
		exit(0);
		}
	close(connfd);
	}
}