#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#define BS 100

int main(int argc, char** argv) 
{
    char wm[BS];
    char rm[BS];
    strncpy(wm,argv[1],BS);

    int fd[2];
    pipe(fd);

    int pid = fork();
    if(pid>0)
    {
        printf("%s\n ",argv[1]);
        close(fd[0]);
        write(fd[1],wm,strlen(wm)+1);


    }
    else if(pid == 0)
    {
        close(fd[1]);
        read(fd[0],rm,BS);
        for(int i= 0;i<strlen(rm);i++)
        {
            if(isupper(rm[i]))
            {
                rm[i] = tolower(rm[i]);
            }
            else if(islower(rm[i]))
            {
                rm[i] = toupper(rm[i]);
            }
        }
        FILE *fp;
        fp = fopen(argv[2], "w") ; 
        if ( fp == NULL ) 
            { 
                printf( "file failed to open." ) ; 
            } 
        else
        { 
            
            // printf("The file is now opened.\n") ; 
            
            // Write the dataToBeWritten into the file 
            if ( strlen (rm) > 0 ) 
            { 
                
                // writing in the file using fputs() 
                fputs(rm, fp) ;    
                fputs("\n", fp) ; 
            } 
            
            // Closing the file using fclose() 
            fclose(fp) ; 
            
            // printf("Data successfully written in file GfgTest.c\n"); 
            // printf("The file is now closed.") ; 
        } 
        close(fd[0]);
    }

}
