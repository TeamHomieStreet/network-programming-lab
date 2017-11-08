#include <sys/socket.h>
#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
	int n;
	unsigned int m = sizeof(n);
	int fdsocket;
	fdsocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 
	getsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(void *)&n, &m);
	cout<<"TCP Receive buffer size: "<<n<<endl;
	getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&n, &m);
	cout<<"TCP Send buffer size: "<<n<<endl;


	n= 20480;
	cout<<"sets the send buffer to: "<<n<<endl;
 	int res = setsockopt(fdsocket, SOL_SOCKET, SO_SNDBUF, (void *)&n, sizeof(n));

 	if(res == -1)
      printf("Error setsockopt");

  	getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&n, &m);
	cout<<"TCP Send buffer size after change: "<<n<<endl;


	n = 20480;
	cout<<"sets the receive buffer to: "<<n<<endl;
	res = setsockopt(fdsocket, SOL_SOCKET, SO_RCVBUF, (void *)&n, sizeof(n));

 	if(res == -1)
      printf("Error setsockopt");

  	getsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(void *)&n, &m);
	cout<<"TCP Receive buffer size after change: "<<n<<endl;

}
