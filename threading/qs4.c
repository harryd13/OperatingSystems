#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include<time.h> 
#include<math.h>

int in_sq= 0;
int in_cr= 0;

void* Circle(void* param) 
{ 
    float* arr = (float*) param;
    double distsq = ((arr[0] - 0.5)*(arr[0] - 0.5) + (arr[1] - 0.5)*(arr[1] - 0.5));
    double dist = sqrt(distsq);
    //rintf("dist = %f\n",dist);
    if(dist <= 0.5 && arr[0] <= 1 && arr[1] <= 1){in_cr++;}

    pthread_exit(0);
    
} 

int main()
{
    srand(time(NULL));
    pthread_t tid;
    pthread_attr_t  attr;
    pthread_attr_init(&attr);
    for(int i = 0;i<10000;i++){
        in_sq++;
        float coords[2]= {0,0};
        coords[0] =(float)(rand()% 1000001)/1000000;
        coords[1] = (float)(rand()% 1000001)/1000000;
        //printf("%f,%f\n",coords[0],coords[1]);
        pthread_create(&tid,&attr,Circle,coords);
        
    }
    for(int i= 0;i<10000;i++)
    {
        pthread_join(tid,NULL);
    }
    
    printf("%d ,%d\n",in_cr,in_sq);
    double pi = 4*((double)in_cr/in_sq);
    printf("value of pi : %f\n",pi);
    return 0;
}


