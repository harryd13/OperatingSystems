#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int n,arr1[100];

void merge(int l,int m,int h)
{
  int arrt1[100],arrt2[100];
  int i,j,k;
  int siez1,siez2;
  siez1 = m-l+1;
  siez2 = h-m;
  i=0;j=0;

  for (i = 0; i <siez1; i++)
  {
    arrt1[i] = arr1[i+l];
  }
  for (i = 0; i < siez2; i++)
  {
    arrt2[i] = arr1[i+m+1];
  }

i=0;j=0;k=l;
  while ((i<siez1) && (j<siez2))
  {
    if (arrt1[i]>arrt2[j])
    {
      arr1[k] = arrt2[j] ;
      j+=1;k+=1;
    }
    else
    {
      arr1[k] = arrt1[i] ;
      i+=1;k+=1;
    }
  }

  while(i<siez1)
  {
    arr1[k] = arrt1[i];
    k++;i++;
  }
  while (j<siez2)
  {
    arr1[k] = arrt2[j];
    k++;j++;
  }


}

void printout(int i,int j)
{

  printf("\n printout\n");

  for (int k = i; k <=j; k++)
  {
       printf(" %d ",arr1[k] );
  }

}



void mergesort(int l , int h)
{
  int mid;
  if (l<h)
  {
      mid = l+h;
      mid=mid/2;
      int pid = vfork();
      if(pid >0)
      {
        //parent
      // printf("  l =  %d h =  %d\n",l,mid );
        mergesort(l,mid);
      }
      else
      {
      // printf("  l =  %d h =  %d\n",l,mid );
        mergesort(mid+1,h);
        exit(1);
      }

      wait(NULL); //wait for both sides
      merge(l,mid,h);
      //printout(l,h);
  }

}






int main(int argc, char const *argv[])
{
  printf("Enter the number of values \n" );
  scanf("%d",&n);
  printf("Enter the values:\n" );
  printf("n = %d\n",n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d",&arr1[i]);
  }
  // for (i = 0; i < n; i++) {
  //   printf(" %d ",arr1[i] );
  // }

  mergesort(0,n-1);
  // merge(0,3,6);
  printf("\nSorted list: \n" );
  for (i = 0; i < n; i++) {
    printf(" %d ",arr1[i] );
  }
  return 0;
}


// 12
// 43
// 65
// 76
// 4
// 23
// 11
