#include<iostream>
#include<algorithm>
#include <queue> 

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
bool compareTwojobs(packet a, packet b) 
{ 
    
    // If burst time is different
    // returns true for less bt 
    if (a.bt != b.bt) 
            return a.bt < b.bt; 
    
    
    // If bt is same but arrival time is not same then 
    // returns true for lower arrival 
    if (a.at != b.at ) 
        return a.at < b.at; 
  
    return (a.pid < b.pid); 
} 
void SortedProcessQueue_AT(packet process[], int n) 
{ 
    // Sort structure array using user defined 
    // function compareTwoArrivals() 
    sort(process, process+n, compareTwoArrivals); 

} 
void SortedProcessQueue_BT(packet process[], int n) 
{ 

    // Sort structure array using user defined 
    // function compareTwoArrivals() 
    sort(process, process+n, compareTwojobs); 

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
    float avg = 0;
    int timer = 0;
    int cnt = 0;
    int Pseudo_Ct;
    packet p[n];
    packet ps[n];
    queue<packet> readyQ;
    packet ready;
    int change = 0;
    int minbt= __INT_MAX__;
    for(int i = 0;i<n;i++){
        p[i].pid = i+1;
        p[i].at = rand()%10;
        p[i].bt = rand()%10;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
        
    } 
    printTable(p,n);
    SortedProcessQueue_AT(p, n);
        ////till here : a (AT)sorted array of packets is available 
    
printf("___________________________________________\n");
    p[0].ct = p[0].at + p[0].bt; 
    //fill ready 
    ps[0] = p[0];
    for(int i = 1;i<n;i++)
    {
        minbt= __INT_MAX__;
        for(int j = 1;j<n;j++)
        {
            Pseudo_Ct = ps[i-1].ct;

            if(p[j].at <= Pseudo_Ct )
            {
                if(p[j].bt < minbt)
                {
                    cnt++;
                    ready = p[j];
                    minbt = p[j].bt;
                    change = j;
                                      
                }
           }
        }
        if(cnt == 0)
        {
            //no new arrival yet cpu sits ideal
            Pseudo_Ct = Pseudo_Ct + p[i].at;

        }
        else
        {
            ps[i] = ready;
            p[change].at = __INT_MAX__;
            ps[i].ct = ps[i].bt + ps[i-1].ct;
        }
    }

    for(int i = 1;i<n;i++){
      
        ps[i].ct = ps[i-1].ct + ps[i].bt;
        
    } 
    for(int i = 0;i<n;i++){
      
        ps[i].tat = ps[i].ct - ps[i].at;
        ps[i].wt = ps[i].tat - ps[i].bt;
        
    } 
    
    printf("______________________________________________\n");
    printTable(ps,n);
    int sum = 0;
    for (int i = 0 ; i <n;i++)
    {
        sum = ps[i].wt + sum;
    }
    avg = sum/n;
    printf("\n\nThe average waiting time = %f\n",avg);

    
    
    return 0;
}
