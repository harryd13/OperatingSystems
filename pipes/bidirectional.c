#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define BS 255

int main()
{
    char wm[BS] = "I AM HARMAN";
    char wm2[BS] = "I am a good boy";
    char rm[BS] ;
    char rm2[BS] ; 
    char fixed_str[] = "but i am never able to do my homework at time\n"; 

    int fd1[2];
    int fd2[2];
    // int fd3[2];
    //int fd4[2];
    pipe(fd1);
    pipe(fd2);
    // pipe(fd3);
    //pipe(fd4);

    int pid;
    pid = fork();
    if(pid > 0)
    {
        close(fd1[0]); //fd[0] is used to read
        write(fd1[1],wm,strlen(wm) + 1);
        printf("sender:this is parent\n");
        close(fd1[1]);

    
        wait(NULL);
        close(fd2[1]); // Close writing end of second pipe 
  
        // Read string from child, print it and close 
        // reading end. 
        printf("reciever (parent):\n");
        read(fd2[0], rm2,BS); 
        printf("%s\n",rm2);
        close(fd2[0]); 
    }
    else if(pid == 0)
    {
        printf("reciever (child):\n");
        close(fd1[1]);
        read(fd1[0],rm,BS);
        printf("%s\n",rm);
        close(fd1[0]);

        
  
        // Write concatenated string and close writing end 
        printf("sender:this is child\n");
        close(fd1[0]);
        write(fd2[1],wm2, strlen(wm2)+1); 
        close(fd2[1]); 
  
        exit(0); 
    }

return 0;
}