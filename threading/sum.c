
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
void *runner(void *param);
int sum = 0;

int main(int argc,char** argv)
{
    int n = atoi(argv[1]);
    pthread_t tid;
    pthread_attr_t  attr;
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,argv[1]);
    pthread_join(tid,NULL);
    printf("------------Sum usingthreading---------------\n");
    printf("|  entered Upper limit = %d                 |\n",n);
    printf("|  ...                                      |\n");
    printf("|  ...                                      |\n");
    printf("|  Summation is = %d                        |\n",sum);
    printf("|  THANKYOU!!!                              |\n");
    printf("|                                           |\n");
    printf("|                                           |\n");
    printf("|                                           |\n");
    printf("---------------------------------------------\n");

return 0;
}
void *runner(void *param) 
{ 
    int ul = atoi(param);
    for(int i = 1;i<=ul;i++)
    {
        sum += i;
    }
    pthread_exit(0);
    
} 
