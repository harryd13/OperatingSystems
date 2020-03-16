#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

int main() 
{
    int n = 20;
    printf("Enter the number of terms required\n");
    scanf("%d",&n);
    int pid = fork();
    if(pid == 0)
    {//child block
        int i = 3, count, c;
 
        
 
        if ( n >= 1 )
        {
            printf("First %d prime numbers are :\n",n);
            printf("2\n");
        }
 
        for ( count = 2 ; count <= n ;  )
        {
            for ( c = 2 ; c <= i - 1 ; c++ )
            {
                if ( i%c == 0 )
                    break;
            }
            if ( c == i )
            { 
                printf("%d\n",i);
                count++;
            }
            i++;
        }
    }

    else if(pid > 0)
    {//parent block
        sleep(2);
        printf("Fibbonacci series by parent\n");
        int first = 0, second = 1, next, c;
 
        printf("First %d terms of Fibonacci series are:\n", n);
 
        for (c = 0; c < n; c++)
        {
            if (c <= 1)
            next = c;
            else
            {
                next = first + second;
                first = second;
                second = next;
            }
            printf("%d\n", next);
        }
    }
    return 0; 
} 