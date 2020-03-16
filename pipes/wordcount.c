#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

#define BS 255

int main()
{
    char wm[BS] = "my name is Harman\n. I live in chennai. My hometown is Jaipur";
    char tocompare[BS];
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
        int chars = 0;
        int words = 1;
        int lines = 1;
        int sentences = 1;
        close(fd[1]);
        read(fd[0],rm,BS);
        for(int i = 0;i<strlen(rm)+1;i++)
        {
            chars++;
            if(rm[i] == ' ')
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
        printf("chars = %d\nWords = %d\nLines = %d\nSentences = %d\n",chars,words,lines,sentences);
    }

return 0;
}