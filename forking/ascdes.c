#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSortinc(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void bubbleSortdec(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] < arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
void getArray(int arr[], int size) 
{ 
    printf("enter arr\n");
    int i; 
    for (i=0; i < size ; i++){ 
        scanf("%d", &arr[i]);  
    }
} 
  

int main() 
{
    int s = 10;
    printf("enter arr size\n");
    scanf("%d",&s);
    int arr[s];
    getArray(arr,s);
    int pid = fork();
    if(pid == 0)
    {//child block ascending 
        bubbleSortinc(arr,s);
        printArray(arr,s);

    }
    else if(pid > 0)
    {//parent block descending
        sleep(2);
        bubbleSortdec(arr,s);
        printArray(arr,s);



    }
    return 0; 
} 