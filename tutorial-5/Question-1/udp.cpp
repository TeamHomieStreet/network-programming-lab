#include <sys/socket.h>
#include <iostream>
//#include<fstream>
#include <signal.h>
//#include<unistd.h>
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
	fdsocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP); // example
	getsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(void *)&n, &m);
	cout<<"UDP Receive buffer size: "<<n<<endl;
	getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&n, &m);
	cout<<"UDP Send buffer size: "<<n<<endl;

}