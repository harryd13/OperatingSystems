#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int count = 0;
sem_t S;


void* producer(void* param){
    sem_wait(&S);
    count++;
    printf("count >> %d\n",count);
    sem_post(&S);
    pthread_exit(0);
}

void* consumer(void* param){
    sem_wait(&S);
    count--;
    printf("count << %d\n",count);
    sem_post(&S);
    pthread_exit(0);
}



int main(){
    
    pthread_t tid[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int t= 0;
    sem_init(&S,0,1);
    while(t<10){
        pthread_create(&tid[0],&attr,producer,NULL);
        pthread_create(&tid[1],&attr,consumer,NULL);
        t++;
    }
    t= 0;
    while (t<10)
    { 
        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
        t++;
    }
    
return 0;
}