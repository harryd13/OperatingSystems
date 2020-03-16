#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include<time.h>
#include <pthread.h> 
#define S 101


int numbers[S];

float q1;
float q3;

float median();
void * find_q1(void * para);
void * find_q3(void * para);


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int main()
{

    srand(time(NULL));
    for (int i = 0; i < S; i++)
    {
        numbers[i] = rand()%100;
    }
    qsort(numbers,S,sizeof(int),cmpfunc);
    printf("_______________________\n");
    printf("_______________________\n");
    for(int i = 0;i<S;i++)
    {
        printf("%d\n",numbers[i]);
    }

    float medd = median();
    pthread_t tid[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&tid[1],&attr,mode,NULL);
    pthread_create(&tid[2],&attr,mean,NULL);
    
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);

return 0;
}
float median(int* arr,int n){
    float med;
    if((n % 2) != 0)
    {
        med = (float)arr[(n+1)/2];
    }
    else
    {
        med = (float)(arr[(n)/2] + arr[((n)/2)+1])/2 ;
    }
    return med;

}
void * find_q1(void * para ){
    int med_index= (S+1)/2;

    int q1_arr[med_index];
    for(int i = 0;i< med_index;i++)
    {
        q1_arr[i] = numbers[i];

    }
    q1 = median(q1_arr,med_index);
    pthread_exit(NULL);


}
void * mean(void * para){
    int med_index= (S+1)/2;

    int q1_arr[med_index];
    for(int i = med_index;i< S;i++)
    {
        q1_arr[i] = numbers[i];

    }
    q1 = median(q1_arr,med_index);
    pthread_exit(NULL);
    pthread_exit(NULL);
}