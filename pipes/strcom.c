#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define BS 255

int main()
{
    char wm[BS] = "I AM not HARMAN";
    char tocompare[BS] = "I AM HARMAN";
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
    {
        //printf("Iam in child block i read your message\n");
        int flag = 0;
        close(fd[1]);
        read(fd[0],rm,BS);
        for(int i = 0;i<strlen(rm)+1;i++)
        {
            if(rm[i] == tocompare[i])
            {
                flag = 0;
            }
            else
            {
                flag = 1;
                break;
            }
            
        }
        if(flag == 0)
        {
            printf("string sent by parent is same as that of child\n");

        }
        else
        {
            printf("not same\n");       
               
        }
        
        close(fd[0]);
    }

return 0;
}