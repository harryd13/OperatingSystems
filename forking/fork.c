#include <unistd.h>
#include <stdio.h> 
#include <sys/types.h> 
int main(){
    printf("hello\n");
    fork();


    printf("os 2019\n");


    return 0;
}