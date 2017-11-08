#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

int main()
{
    int pid;
    pid=fork();
    if(pid<0)
    {
        printf("\n Error ");
        exit(1);
    }
    else if(pid==0)
    {
	printf("\n child process pid is %d ",getpid());        
	printf("\n Hello I am the child process ");
        

        char *ch[]={"./utility",NULL};
        execvp(ch[0], ch);
        exit(0);
    }
    else
    {
        printf("\n Hello I am the parent process ");
        printf("\n My actual pid is %d \n ",getpid());
        //exit(1);
        //waitpid(pid, &status, 0);
        exit(1);
    }

}
