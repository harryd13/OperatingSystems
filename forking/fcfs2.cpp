#include<iostream>
#include<algorithm>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include<sstream>

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
    string Str;
    packet p[n];
    int pseudo_ct=0;
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
        //p[i].bt = rand()%50;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
        
    } 


    printTable(p,n);
    SortedProcessQueue(p, n);

    p[0].ct = p[0].at + p[0].bt; 
    printf("___________________________________\n");
    //printTuple(p, 0);

    //________________________this calculates ct
    for(int i = 1;i<n;i++){

        //if new arrival is after ct of first
        if(p[i].at>p[i-1].ct)
        {
            pseudo_ct = p[i].at;
            
        }
    
        else{
        pseudo_ct = p[i-1].ct;
        }

        p[i].ct = pseudo_ct + p[i].bt;
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