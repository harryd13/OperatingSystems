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
string getFileCreationTime(const string& path)
{
    struct stat attr;
    stat(path.c_str(),&attr);
    string s;
    s = ctime(&attr.st_mtime);
    return s;
}
size_t getFilesize(const string& filename)
{
    struct stat st;
    if(stat(filename.c_str(),&st) != 0){
        return 0;
    }
    return st.st_size;
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
    packet ready;
    int change = 0;
    int minbt= __INT_MAX__;
    string Str;

        Str = getFileCreationTime("one.txt");
        p[0].at = stoi(Str.substr(17,2));
        Str = getFileCreationTime("two.txt");
        p[1].at = stoi(Str.substr(17,2));
        Str = getFileCreationTime("three.txt");
        p[2].at = stoi(Str.substr(17,2));
        Str = getFileCreationTime("four.txt");
        p[3].at = stoi(Str.substr(17,2));
        Str = getFileCreationTime("five.txt");
        p[4].at = stoi(Str.substr(17,2));  


        //filesize
        
        p[0].bt = getFilesize("one.txt");        
        p[1].bt = getFilesize("two.txt");
        p[2].bt = getFilesize("three.txt");
        p[3].bt = getFilesize("four.txt");
        p[4].bt = getFilesize("five.txt");



    for(int i = 0;i<n;i++){
        p[i].pid = i+1;
        //p[i].at = rand()%10;
        //p[i].bt = rand()%10;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
        
    } 

    printTable(p,n);
    SortedProcessQueue_AT(p, n);
    
        ////till here : a (AT)sorted array of packets is available 
    
    cout << "________________________________________________________________\n" ;
//_________calculation of ct
    p[0].ct = p[0].at + p[0].bt; ///
    //fill ready 
    ps[0] = p[0];   
               ///
    for(int i = 1;i<n;i++)       ///to fill ps[]
    {
        Pseudo_Ct = ps[i-1].ct;  
        minbt= __INT_MAX__;      ///to initialize min for each index
        for(int j = 1;j<n;j++)   ///to find next readyq process
        {
               

            if(p[j].at <= Pseudo_Ct )//if new arrives before ct of previous
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
            ps[i-1].ct = Pseudo_Ct + p[i].at;
            //cout << "Hello am i seen?";
            ps[i] = p[i];
            ps[i].ct = ps[i-1].ct + ps[i].bt;

        }
        else
        {
            ps[i] = ready;
            p[change].at = __INT_MAX__;
            ps[i].ct = ps[i].bt + ps[i-1].ct;
        }
    }
    ps[0] = p[0];
    /* for(int i = 1;i<n;i++){
      
        ps[i].ct = ps[i-1].ct + ps[i].bt;
        
    }*/
    for(int i = 0;i<n;i++){
      
        ps[i].tat = ps[i].ct - ps[i].at;
        if(ps[i-1].ct < ps[i].at)
        {
            ps[i].wt = 0;
        }
        else{
        ps[i].wt = abs(ps[i].tat - ps[i].bt);
        }
        
    } 
    
    //printf("____________________________________________________________________\n");
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
