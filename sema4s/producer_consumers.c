#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int count = 0;

int Buffer[10];

void* producer(void* param){
    int in = 0;
    while(1){
        while(count == 10){
            //do nothing when buffer is already filled
        }
        Buffer[in] = 8;
        printf("item 8 produced\n");
        in = (in+1)%10;
        count++;
        printf("count == %d made yet\n",count);
    }
    pthread_exit(0);
}

void* consumer(void* param){
    int item;
    int out = 0;
    while(1){
        while(count == 0){
            //wait
        }
        item = Buffer[out];
        printf("item 8 consumed\n");
        out = (out+1)%10;
        count--;
        printf("count == %d now\n",count);
    }
    pthread_exit(0);
}



int main(){
    
    pthread_t tid[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid[0],&attr,producer,NULL);
    pthread_create(&tid[1],&attr,consumer,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
   
}