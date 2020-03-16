
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
// void *runner(void *param);
int m = 3;
int n = 3;
int k = 2;

int A[3][2]= {{1,2},{3,4},{5,6}};
int B[2][3]= {{7,8,9},{10,11,12}};
int C[3][3];
struct DT{
    int dti;
    int dtj;
};

void *runner(void *param) 
{ 
    int sum = 0;
    struct DT* data = param;
    for(int n = 0;n<k;n++)
    {
        sum = sum + A[data->dti][k]*B[k][data->dtj];
        
    }
    C[data->dti][data->dtj] = sum;
    pthread_exit(0);
    
} 




int main(int argc,char** argv)
{
    int i ,j = 0;
    pthread_t tid;
    pthread_attr_t  attr;
    pthread_attr_init(&attr);
    
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            struct DT* data = (struct DT*)malloc(sizeof(struct DT));
            data->dti = i;
            data->dtj = j;
            
            pthread_create(&tid,&attr,runner,data);
            
            
        }
           
        
    }
    pthread_join(tid,NULL);
    //printmat(A,m,k);
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<k;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    //printmat(B,k,n);
    for(int i = 0;i<k;i++)
    {
        for(int j = 0;j<n;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    //printmat(C,m,n);
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

return 0;
}

