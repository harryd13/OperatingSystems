#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define BS 255


int main()
{
    char wm[BS] = "NITIN";
    char rm[BS] ;
    char rm2[BS] ; 

    int fd1[2];
    //int fd2[2];

    pipe(fd1);
    //pipe(fd2);
    
    int pid;
    pid = fork();
    if(pid > 0)
    {
        close(fd1[0]); //fd[0] is used to read
        write(fd1[1],wm,strlen(wm) + 1);
        printf("check this string by parent for palindrome and reverse it\n");
        close(fd1[1]);

    }
    else if(pid == 0)
    {
        printf("reciever (child):\n");
        close(fd1[1]);
        read(fd1[0],rm,BS);
        //strcpy(rm, rm2);  // Copying input string
        int i ;
        int j=strlen(rm)-1;
        for(i = 0;i<strlen(rm);i++)
        {
            rm2[j] = rm[i];
            j--;
        }
        rm2[strlen(rm)] = '\0';
        printf("%s\n",rm);
        printf("rm2 : %s\n",rm2);

        printf("%s\n",rm2);
        if (strcmp(rm, rm2) == 0)  // Comparing input string with the reverse string
            printf("The string is a palindrome.\n");
        else
            printf("The string isn't a palindrome.\n");

        close(fd1[0]);
    }

return 0;
}