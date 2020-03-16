#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

#define BS 1000

int main()

{
    // char *wm[BS];

    char tocompare[BS];
    char rm[BS] ;

    int fd[2];
    pipe(fd);

    int pid;
    pid = fork();
    if(pid > 0)
    {
        int flag = 0;
        int chars = 0;
        int words = 1;
        int lines = 0;
        int sentences = 1;
        close(fd[1]);
        read(fd[0],rm,BS);
        for(int i = 0;i<strlen(rm)+1;i++)
        {
            chars++;
            if(rm[i] == ' ' || '\n')
            {
                words++;
            }
            if(rm[i] == '\n')
            {
                lines++;
            }
            if(rm[i] == '.')
            {
                sentences++;
            }
            
        }
        
        close(fd[0]);
        printf("chars = %d\nWords = %d\nfiles = %d\nSentences = %d\n",chars,words,lines,sentences);

        

    }
    else if(pid == 0)
    {
        //printf("Iam in child block i read your message\n");
        dup2(fd[1],1);
        execlp("ls","ls","-l",NULL);
    }
return 0;
}