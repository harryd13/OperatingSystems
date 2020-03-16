#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

int main() 
{
    int s[20];
    // make two process which run same 
    // program after this instruction
    int pid = fork();
    if(pid == 0){//child block
    sleep(0.5);
        printf("even series by child\n");
        

        for(int i = 0;i<20;i++)
        {
            if(i % 2 == 0)
            {
                s[i] = i;
            }
             else{
                s[i] = -1;
            }
        }
        

    }
    else if(pid > 0){//parent block
    printf("odd series by parent\n");
        for(int i = 0;i<20;i++)
        {
            
            if(i % 2 != 0)
            {
                s[i] = i;
            }
            else{
                s[i] = -1;
            }
        }


    }
    for(int i = 0;i<20;i++)
        {
           if(s[i] != -1)
            {
                printf("%d \n",s[i]);
            }
        }
    return 0; 
} 
