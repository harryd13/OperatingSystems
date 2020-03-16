#include <stdio.h>
#include <stdlib.h>	//to use system()
#include <string.h> //to use strcpy()

int main()
{
    char * new;
    printf("enter :");
    scanf("%[^\n]%*c",new);
    system(new);
}