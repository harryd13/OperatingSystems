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

int main() 
{
    int s[20];
    printf("enter 20 int in array:\n");
    for (int i = 0;i<20;i++)
    {
        scanf("%d",&s[i]);
    }

    int fd[2];
    int val = 0;
    pipe(fd);
    int pid = fork();
    if(pid == 0)
    {//child block

        
        sleep(5);
        close(fd[1]);

        // now read the data (will block)
        for(int j = 0;j<10;j++)
        {
            read(fd[0], &val, sizeof(val));
            s[j] = val;
        }

        // close the read-descriptor
        close(fd[0]);
        
        int i, j; 
        for (i = 10; i < 20 -1; i++)       
        // Last i elements are already in place    
        for (j = 10; j < 20-1; j++)  
           if (s[j] < s[j+1]) 
              swap(&s[j], &s[j+1]);

        printArray(s,20);

    }
    else if(pid > 0)
    {//parent block
        int i, j; 
        for (i = 0; i < 10 -1; i++)       
        // Last i elements are already in place    
        for (j = 0; j < 10-i-1; j++)  
           if (s[j] > s[j+1]) 
              swap(&s[j], &s[j+1]);

        close(fd[0]);
        for(int j = 0;j<10;j++)
        {
        val = s[j];
        write(fd[1], &val, sizeof(val));
        //printf("Parent(%d) send value: %d\n", getpid(), val);

        }
        
        close(fd[1]);
    }
    return 0; 
} 
