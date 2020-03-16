#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define BS 255

int main()
{
    char wm[BS] = "I AM HARMAN";
    char rm[BS] ;

    int fd[2];
    pipe(fd);

    int pid;
    pid = fork();
    if(pid > 0)
    {//child block
        close(fd[0]); //fd[0] is used to read
        write(fd[1],wm,strlen(wm) + 1);
        printf("this is parent writing\n");
        close(fd[1]);
    }
    else if(pid == 0)
    {//parent block
        printf("Iam in child block i read your message\n");
        close(fd[1]);
        read(fd[0],rm,BS);
        printf("%s\n",rm);
        
        close(fd[0]);
    }

return 0;
}