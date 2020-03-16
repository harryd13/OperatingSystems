#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#define S 10

int numbers[S];
float meen;
float med;
int mod;

void * median(void * para);
void * mode(void * para );
void * mean(void * para);


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int main()
{

    printf("Enter 10 numbers :\n");
    for (int i = 0; i < S; i++)
    {
        scanf("%d",&numbers[i]);
    }
    qsort(numbers,S,sizeof(int),cmpfunc);
    printf("_______________________\n");
    printf("_______________________\n");
    for(int i = 0;i<S;i++)
    {
        printf("%d\n",numbers[i]);
    }
    pthread_t tid[3];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid[0],&attr,median,NULL);
    pthread_create(&tid[1],&attr,mode,NULL);
    pthread_create(&tid[2],&attr,mean,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);

    printf("the mean for given array is %f\n",meen);
    printf("the median for given array is %f\n",med);
    printf("the mode for given array is %d\n",mod);

return 0;
}
void * median(void * para){
    if((S % 2) != 0)
    {
        med = (float)numbers[(S+1)/2];
    }
    else
    {
        med = (float)(numbers[(S)/2] + numbers[((S)/2)+1])/2 ;
    }
    pthread_exit(NULL);

}
void * mode(void * para ){
    int freq = 0;
    int m;
    int currnt = 0;
    for(int i = 0;i<S;i++)
    {
        if(currnt != numbers[i])
        {
            m = freq;
            freq = 0;
            currnt = numbers[i];
        }
        else{
            freq += 1;
        }
        if(m < freq)
        {
            m = freq;
            mod = numbers[i];
        }
    
    }
    pthread_exit(NULL);


}
void * mean(void * para){
    int sum = 0;
    for (int i = 0;i <S;i++)
    {
        sum += numbers[i];
    }
    float avg = (float)sum/S;
    meen = avg;
    pthread_exit(NULL);
}