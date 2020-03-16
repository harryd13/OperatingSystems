// #include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<sys/wait.h>
// #include<sys/types.h>


int main()
{
    char command[1000];
    printf("enter the command:");

    scanf("%[^\n]%*c", command);
    printf("%s\n",command);
    printf("%ld",strlen(command));
    

return 0; 
}