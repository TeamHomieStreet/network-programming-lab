#include <sys/types.h>	
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>	
#include <netinet/in.h>
#include <arpa/inet.h>	
#include <errno.h>
#include <fcntl.h>	
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>	
#include <sys/uio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>
#include <mqueue.h>
#include <sys/msg.h>


int main(int argc, char** argv){
    mqd_t mqd;
    struct mq_attr attr;

    if (argc != 4) {printf("usage: q1 <name> <len> <priority>"); exit(0);}

    mqd = mq_open(argv[1], O_RDWR | O_CREAT);

    mq_getattr(mqd, &attr);
    printf("max #msgs = %ld, max#bytes/msg = %ld, ""#currently on queue = %ld\n", attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

    size_t len = atoi(argv[2]);
    uint32_t prio = atoi(argv[3]);

    void* ptr = calloc(len, sizeof(char));
    mq_send(mqd, ptr, len, prio);
    mq_close(mqd);
    exit(0);
}
