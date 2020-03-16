#include<stdio.h>

char *command;
char buff[255];

int main()
{
    
    FILE *p,*q;
    int stat;

    //p = fopen("one.txt", "a");
    q = fopen("one.txt", "r");

    if(q == NULL)
    {
        printf("can't open the file\n");

    }

    //printf("Enter command:");
    //scanf("%s", command);
    //fprintf(p,"%s \n",command);
    //fclose(p);
    do
    {
        stat = fgets(buff,sizeof(buff),q);
        printf("%s",buff);
    }
    while(stat);
    fclose(q);
return 0;
}