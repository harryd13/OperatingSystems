#include <stdio.h>
#include <stdlib.h>	//to use system()
#include <string.h> //to use strcpy()

int main()
{

	char *command;
	FILE *p,*q;
	char buff[255];
	int stat;
	
	while(strcmp(command,"exit") != 0)
	{
		//make a buffer
		
		printf("youAcces%mycomp>>> ");
		scanf("%[^\n]%*c", command); 

		//execute this command using system
		system(command);

		//write to new file line
		
    	p = fopen("hist.txt", "a+");
	
		fprintf(p,"%s\n",command);
		fclose(p);

		
	}

	int ans = 0;
	printf("to see command hostory enter 1: ");
	scanf("%d",&ans);
	if(ans == 1){
		q = fopen("hist.txt", "r");
		if(q == NULL)
    	{
       		printf("can't open the file\n");

    	}
		do
    	{
        	stat = fgets(buff,sizeof(buff),q);
        	printf("%s",buff);
    	}
    	while(stat);

	fclose(fopen("hist.txt", "w"));
		
    fclose(q);
 		
	}
	

	
	return 0;
}