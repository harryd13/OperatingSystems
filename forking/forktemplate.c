#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

int main() 
{
    int pid = fork();
    if(pid == 0)
    {//child block

    }
    else if(pid > 0)
    {//parent block

    }
    return 0; 
} 
