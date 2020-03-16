#include <stdio.h> 

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

int main()
{
    int s[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int i, j; 
    for (i = 10; i < 20 -1; i++)       
        // Last i elements are already in place    
        for (j = 10; j < 20-1; j++)  
           if (s[j] < s[j+1]) {
              //swap(&s[j], &s[j+1]);
              int tmp;
              tmp = s[j];
              s[j] = s[j+1];
              s[j+1] = tmp;
           }
    for(int k = 0;k<20;k++)
    {
        printf("%d ",s[k]);
    }
return 0;
}