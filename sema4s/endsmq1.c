#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#define WOOFER 3
#define WOOFERHOUSE 4
#define TWEETER 5
#define TWEETERHOUSE 6
#define SZ 10

int count = 0;
int cincount = 0;
int princount = 0;
int cindrella[5];
int prince[5];


sem_t mutex;


int Buffer[10] = {1,2,WOOFER,WOOFERHOUSE,TWEETER,TWEETERHOUSE,7,8,9,10};

void* cinder_ella(void* param){
    int item;
    if(cincount >= 5){
        pthread_exit(0);
    }
    
    int index = rand()%10;
    
    while(count == 10){
        //do nothing when buffer is already filled
    }
    while(Buffer[index]==-1 || Buffer[index]==-2)
        index = rand()%10;


    sem_wait(&mutex);
    item = Buffer[index];
    printf("cindrella wants %d \n",item);
    if((item!= -1) && (item != -2)){
        if(item == WOOFER){
            cindrella[cincount]= item;
            Buffer[index] = -1;
            printf("cindrella gets WOOFER \n");
            cindrella[cincount+1] = WOOFERHOUSE;
            Buffer[index+1] = -1;
            printf("cindrella gets WOOFERHOUSE\n");
            cincount = cincount+2;
        }
        else if(item == WOOFERHOUSE){
            cindrella[cincount]= item;
            Buffer[index] = -1;
            printf("cindrella gets WOOFERHOUSE \n");
            cindrella[cincount+1] = WOOFER;
            Buffer[index-1] = -1;
            printf("cindrella gets WOOFER\n");
            cincount = cincount+2;
        }
        else if(item == TWEETER){
            cindrella[cincount]= item;
            Buffer[index] = -1;
            printf("cindrella gets TWEETeR \n");
            cindrella[cincount+1] = TWEETERHOUSE;
            Buffer[index+1] = -1;
            printf("cindrella gets TWEETERHOUSE\n");
            cincount = cincount+2;
        }
        else if(item == TWEETERHOUSE){
            cindrella[cincount]= item;
            Buffer[index] = -1;
            printf("cindrella gets TWEETERHOUSE \n");
            cindrella[cincount+1] = TWEETER;
            Buffer[index-1] = -1;
            printf("cindrella gets TWEETER\n");
            cincount = cincount+2;
        }
        else{
            cindrella[cincount] = item;
            cincount++;
            printf("cindrella gets %d \n",item);
            Buffer[index] = -1;
        }
    }
    else
    {
        printf("cindrella did not get %d \n",item);
    }
    count++;
    

    sem_post(&mutex);
    sleep(0.2);
        
    
    pthread_exit(0);
}

void* pri_nce(void* param){
    if(princount >= 5){
        pthread_exit(0);
    }
    int item;
    int index = rand()%10;
    
    while(count == 10){
        //do nothing when buffer is already filled
    }
    while(Buffer[index]==-1 || Buffer[index]==-2)
    {
            index = rand()%10;
    }
    sem_wait(&mutex);
    item = Buffer[index];
    printf("prince wants %d \n",item);
    if((item!= -1) && (item != -2)){
        if(item == WOOFER){
            prince[cincount]= item;
            Buffer[index] = -2;
            printf("prince gets WOOFER \n");
            prince[cincount+1] = WOOFERHOUSE;
            Buffer[index+1] = -2;
            printf("prince gets WOOFERHOUSE \n");
            princount = cincount+2;
        }
        else if(item == WOOFERHOUSE){
            prince[princount]= item;
            Buffer[index] = -2;
            printf("prince gets WOOFERHOUSE \n");
            prince[princount+1] = WOOFER;
            Buffer[index-1] = -2;
            printf("prince gets WOOFER\n");
            princount = princount+2;
        }
        else if(item == TWEETER){
            prince[cincount]= item;
            Buffer[index] = -2;
            printf("prince gets TWEETER \n");
            prince[cincount+1] = TWEETERHOUSE;
            Buffer[index+1] = -2;
            printf("prince gets TWEETERHOUSE \n");
            princount = cincount+2;
        }
        else if(item == TWEETERHOUSE){
            prince[cincount]= item;
            Buffer[index] = -2;
            printf("prince gets TWEETERHOUSE \n");
            prince[princount+1] = TWEETER;
            Buffer[index-1] = -2;
            printf("prince gets TWEETER\n");
            princount = princount+2;
        }
        else{
            prince[princount] = item;
            princount++;
            printf("prince gets %d \n",item);
            Buffer[index] = -2;
        }
    }
    else
    {
        printf("prince did not get %d \n",item);
    }
    count++;
    
    sem_post(&mutex);
    sleep(0.2);
        
    
    pthread_exit(0);
}

void printarr(int arr[])
{
    for(int i= 0;i<SZ;i++)
    {
        printf("%d\n",arr[i]);
    }
}



int main(){
    srand(time(NULL));
    int d1= 0;
    int d2= 0;
    sem_init(&mutex,0,1);
    pthread_t tid[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    while(1){
        pthread_create(&tid[0],&attr,cinder_ella,NULL);
        
        pthread_create(&tid[1],&attr,pri_nce,NULL);
        pthread_join(tid[0],NULL);
       pthread_join(tid[1],NULL);
       if(cincount==5 && princount==5)
        break;
    
    }
    
    // printf("____________________________cindrella\n");
    // printarr(cindrella);
    // printf("____________________________prince\n");
    // printarr(prince)
    printarr(Buffer);
   
}