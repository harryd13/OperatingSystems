#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

// char * readline (const char *prompt);
void parse(char *string1 ,char **argv)
{

    while (*string1!='\0')
    {
      while (*string1==' ')
      {
        *string1 ='\0';
        *string1++;
      }
        *argv = string1;
        *argv++;
      while (*string1!='\0' && *string1!= ' ')
      {
        string1++;

      }
    }
    *argv = '\0';
}


int main()
{
  int pid,i,j;
  // char *sr1;
  char sr1[1000];

  int flag = 1;
  char *cmd1[100];
  char temph[100];
  char nu1m;
  // char **cmd1;

  int counti = 0,countj=0;
  int id1=0;
  char nu2m ;
  FILE * fp1;
  
  while(1)
  {
    printf(">>$" );
    gets(sr1);
    
    if (!strcmp(sr1,"EXIT")) {
      printf("Thanks for using\nBYE\n" );

      break;
      exit(1);
    }

    for (i = 0; sr1[i]!=' '; i++)
    {
      temph[i]=sr1[i];
    }
    nu1m = sr1[i+1];
    nu2m = sr1[i+2];
    temph[i+1] = '\0';
    if (!strcmp(temph,"history"))
    {
      char temph1[100] = {'t','a','i','l',' ', 'h','i','s','t','o','r','y','.','t','x','t',' ','-','n','-','@'};
      for (i = 0; temph1[i]!='@'; i++) {;    }
      temph1[i] = nu1m;
      temph1[i+1] = nu2m;
      temph1[i+2] = '\0';
      system(temph1);
      printf("\n%s\n",temph1 );
      continue;
    }
    fp1 = fopen("history.txt","a");
    fputs(sr1,fp1);
    fputs("\n",fp1);
    fclose(fp1);
    
    parse(sr1,cmd1);

    printf("\n" );;
  
    pid = fork();
    if (pid == 0)
    {
        id1 = execvp(*cmd1,cmd1);
        printf("%d\n",id1 );
        
        if (id1<0)
        {
          printf("\nCommand not found\n");
          exit(1);
        }
    }
    else
    {
      wait((int*)NULL);
    }
  }
  return 0;
}