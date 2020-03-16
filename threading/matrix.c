
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
void *runner(void *param);
void printmat(int Arr[][100],int m,int n);

struct DT{
    int dti;
    int dtj;
    int dtk;
    int** a;
    int** b;
};
int C[100][100];

int main(int argc,char** argv)
{
    int i ,j = 0;

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int k = atoi(argv[3]);

    //printf("%d,%d,%d",m,n,k);

    int A[m][k];
    int B[k][n];
    //int C[m][n];
    //________________________________________matrices|
    srand(time(NULL));
    //matrix A
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<k;j++)
        {
            A[i][j] = rand()%10;
        }
    }
    for(i = 0;i<k;i++)
    {
        for(j = 0;j<m;j++)
        {
            B[i][j] = rand()%10;
        }
    }
    //__________________________________________________|
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            struct DT* data = (struct DT*)malloc(sizeof(struct DT));
            data->dti = i;
            data->dtj = j;
            data->dtk = k;
            pthread_t tid;
            pthread_attr_t  attr;
            pthread_attr_init(&attr);
            pthread_create(&tid,&attr,runner,data);
            pthread_join(tid,NULL);
            
        }
    }
    
    printmat(A,m,k);
    printmat(B,k,n);
    printmat(C,m,n);

return 0;
}
void *runner(void *param) 
{ 
    int sum = 0;
    struct DT* data = param;
    for(int k = 0;k<data->dtk;k++)
    {
        sum = sum + data->a[data->dti][k]*data->b[k][data->dtj];
        
    }
    C[data->dti][data->dtj] = sum;
    pthread_exit(0);
    
} 
void printmat(int Arr[][100],int m,int n)
{
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    
}