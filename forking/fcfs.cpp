#include<iostream>
#include<algorithm>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>

using namespace std;

struct packet
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

//functions 
bool compareTwoArrivals(packet a, packet b) 
{ 
    // If arrival time is not same then 
    // returns true for lower arrival 
    if (a.at != b.at ) 
        return a.at < b.at; 
  
    // If at is same but burst time is different
    // returns true for less bt 
    if (a.bt != b.bt) 
            return a.bt < b.bt; 
  
    return (a.pid < b.pid); 
} 
void SortedProcessQueue(packet process[], int n) 
{ 
    // Sort structure array using user defined 
    // function compareTwoArrivals() 
    sort(process, process+n, compareTwoArrivals); 

} 
void printTable(packet process[],int n)
{
    printf("|\tpid|\tAT|\tBT|\tCT|\tTAT|\tWT|\n");
    for(int i = 0;i<n;i++){
        printf("|\t%d|\t%d|\t%d|\t%d|\t%d|\t%d|\n",process[i].pid,process[i].at,process[i].bt,process[i].ct,process[i].tat,process[i].wt);

        
    } 
}
void printTuple(packet process[],int i)
{
    printf("|\tpid|\tAT|\tBT|\tCT|\tTAT|\tWT|\n");
    printf("|\t%d|\t%d|\t%d|\t%d|\t%d|\t%d|\n",process[i].pid,process[i].at,process[i].bt,process[i].ct,process[i].tat,process[i].wt);

        
    
}



int main()
{
    int n = 5; 
    packet p[n];
    for(int i = 0;i<n;i++){
        p[i].pid = i+1;
        p[i].at = rand()%10;
        p[i].bt = rand()%10;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
        
    } 
    printTable(p,n);

    SortedProcessQueue(p, n);

    p[0].ct = p[0].at + p[0].bt; 
    printf("___________________________________\n");
    //printTuple(p, 0);
    for(int i = 1;i<n;i++){
      
        p[i].ct = p[i-1].ct + p[i].bt;
        
    } 
    for(int i = 0;i<n;i++){
      
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        
    } 
    
    printf("___________________________________\n");
    printTable(p,n);
     int sum = 0;
    for (int i = 0 ; i <n;i++)
    {
        sum = p[i].wt + sum;
    }
    float avg = sum/n;
    printf("\n\nThe average waiting time = %f\n",avg);
    
    
    return 0;
}
