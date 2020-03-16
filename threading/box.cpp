

	
	

// g++ 2box\[lot.cpp -std=c++11 -lpthread -o 2bxplt


// ./2bxplt 12 34 54 764 4 6









#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
// #include <sort.h>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
int arr1[100];

struct passdata{
  int strt,end;
  float ans;
  int index1,index2;
};


void *median(void *param)
{
  // int *arg = (int *)(param);
  struct passdata *argh = (struct passdata*)(param);
  // int arglen = *arg;
  int starti,endi,midi,n ;
  starti = argh->strt; endi = argh->end;
  midi = starti+endi+1;

  // midi/=2;
  float mean1 ;
  n = midi/2;

  if (midi%2==0)
  {
    mean1 = arr1[n]+arr1[n-1];
    argh->index1 = n-1;argh->index2 = n;
    mean1/=2;
  }
  else
  {
    mean1 = arr1[n];
    argh->index1 = n-1;
    argh->index2 = n+1;
  }



  argh->ans = mean1;

  pthread_exit(0);

}





int main(int argc, char const *argv[])
{
int i;

  for (i = 1; i < argc; i++)
  {
    arr1[i-1] = atoi(argv[i]);
    // sum1+=arr1[i];
    printf("%d\n",arr1[i-1] );
  }


  sort(arr1,arr1+argc-1);
  pthread_t tid1,tid2,tid3,tid4;
  pthread_attr_t attr;
   pthread_attr_init(&attr);
   struct passdata *argc1 = (struct passdata*)malloc(sizeof(*argc1));
   argc1->strt = 0;
   argc1->end = argc-2;
   // pthread_create(&tid1,&attr,mean,&argc);
   // pthread_create(&tid2,&attr,mode  ,&argc);
   pthread_create(&tid3,&attr,median,argc1);//main median

   pthread_join(tid3,NULL);

   // 1st median 3 rd median 2 whistors
   struct passdata argc2,argc3;
   argc2.strt = 0;
   argc2.end = argc1->index1 ;//1st median
   argc3.strt = argc1->index2;
   argc3.end = argc-2 ;//2st median

   pthread_create(&tid2,&attr,median,&argc2);//first median
   pthread_create(&tid1,&attr,median,&argc3);//second median
   int whistor1 = arr1[0];int whistor2 = arr1[argc-2];

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    std::cout << "\nArray" << '\n';
    for (int i = 0; i < argc-1; i++)
    {

        std::cout << arr1[i] << " ";

    }

    std::cout << "\nWhistor1  " <<whistor1<< '\n';
    std::cout << " median1  " <<argc2.ans<< '\n';
    std::cout << " median " <<argc1->ans<< '\n';
    std::cout << " median2 " <<argc3.ans<< '\n';
    std::cout << "Whistor2  " <<whistor2<< '\n';

    // pthread_attr_t attr;

    //  pthread_attr_init(&attr);
    //  pthread_create(&tid,&attr,m12m,&i);
    // pthread_join(tid,NULL);

    printf("\n%f\n",argc1->ans );






  return 0;
}

2box[lot.cpp
Displaying 2box[lot.cpp.