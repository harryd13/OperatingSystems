#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

int main() 
{
    
    int pid = fork();
    if(pid == 0)
    {//child block
        sleep(2);
        printf("i am an orphan\n");
         printf("process id = %d\n",getpid());
          printf("parent process id = %d\n",getppid());

    }
    else if(pid > 0)
    {//parent block

        printf("i will run and terminate before my child process\n");
        printf("process id = %d\n",getpid());

    }
    return 0; 
} 
