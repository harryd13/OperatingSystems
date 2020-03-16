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
    int fd3[2];
    //int fd4[2];
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    //pipe(fd4);

    int pid;
    pid = fork();
    if(pid > 0)
    {
        close(fd1[0]); //fd[0] is used to read
        write(fd1[1],wm,strlen(wm) + 1);
        printf("this is parent\n");
        close(fd1[1]);

        char concat_str[100]; 
        printf("this is parent for cat\n");
        close(fd2[0]); //fd[0] is used to read
        //write(fd2[1],wm,strlen(wm) + 1);
        write(fd2[1],wm2,strlen(wm2) + 1);
        close(fd2[1]);
        wait(NULL);
        close(fd2[1]); // Close writing end of second pipe 
  
        // Read string from child, print it and close 
        // reading end. 
        read(fd3[0], concat_str, 100); 
        printf("Concatenated string %s\n", concat_str); 
        close(fd3[0]); 
    }
    else if(pid == 0)
    {
        printf("copied message\n");
        close(fd1[1]);
        read(fd1[0],rm,BS);
        printf("%s\n",rm);
        close(fd1[0]);

        printf("concatinated message\n");
        close(fd2[1]);  // Close writing end of first pipe 
        // Read a string using first pipe 
        char concat_str[100]; 
        read(fd2[0], concat_str, 100); 
  
        // Concatenate a fixed string with it 
        int k = strlen(concat_str); 
        int i; 
        for (i=0; i<strlen(fixed_str); i++) 
            concat_str[k++] = fixed_str[i]; 
  
        concat_str[k] = '\0';   // string ends with '\0' 
  
        // Close both reading ends 
        close(fd2[0]); 
        close(fd3[0]); 
  
        // Write concatenated string and close writing end 
        write(fd3[1], concat_str, strlen(concat_str)+1); 
        close(fd3[1]); 
  
        exit(0); 
    }

return 0;
}