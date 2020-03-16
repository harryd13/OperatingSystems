#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define PRMTSIZ 255
#define MAXARGS 63
#define EXITCMD "exit"

char history[256][256];
int indexx=0;

int main() {
    while(1) {
        char input[PRMTSIZ + 1] = { 0x0 };
        char *ptr = input;
        char *args[MAXARGS + 1] = { NULL };
        int wstatus;

        // prompt
        printf("%s ", getuid() == 0 ? "#" : "$");
        fgets(input, PRMTSIZ, stdin);
	    strcpy(history[indexx++],input);
 
        // ignore empty input
        if (*ptr == '\n') continue;

        // convert input line to list of arguments
        for (int i = 0; i < sizeof(args) && *ptr; ptr++) {
            if (*ptr == ' ') continue;
            if (*ptr == '\n') break;
            for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
            *ptr = '\0';
        }

        // built-in: exit
        if (strcmp(EXITCMD, args[0]) == 0) return 0;

        // built-in: cd
        if (args[1] == NULL && strcmp("cd", args[0]) == 0) 
        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  
        else if (chdir(args[1]) != 0 && strcmp("cd", args[0]) == 0) 
            perror("lsh");
 
        // built-in: history
        else if (strcmp("history", args[0]) == 0) 
        for(int j=0 ; j < indexx-1 ; j++)
	    printf("%d. %s",j+1,history[j]);	
   
        // fork child and execute program

        else if (fork() == 0) exit(execvp(args[0], args));

        // wait for program to finish and print exit status
        wait(&wstatus);
        if (WIFEXITED(wstatus)) printf("<%d>", WEXITSTATUS(wstatus));
    }
}