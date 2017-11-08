#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
using namespace std;

int main(){
	struct in_addr ina;
	bzero(&ina, sizeof(ina));
	inet_aton("192.168.121.254", &ina);
	printf("%x\n", ina.s_addr);

}
