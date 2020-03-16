
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
void *runner(void *param);
int sum = 0;

int main(int argc,char** argv)
{
    int m = atoi(argv[1]);
    char arg[1000];
    pthread_t tid;
    pthread_attr_t  attr;
    pthread_attr_init(&attr);
    for(int i = 2;i<m;i++){
        sprintf(arg,"%d",i);
        pthread_create(&tid,&attr,runner,arg);
        pthread_join(tid,NULL);
    }
    
    
    
return 0;
}
void *runner(void *param) 
{ 
    int flag = 0;
    int n = atoi(param);
    //printf("n = %d\n",n);
    for (int i = 2;i<n;i++)
    {
        if (n%i == 0)
        {
            flag = 1;
            //printf("hello");
        }
    }
    if (flag==0)
    {
        printf("%d\n",n);
    }
    pthread_exit(0);
    
    
} 
