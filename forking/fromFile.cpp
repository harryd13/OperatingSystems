#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <iostream>

using namespace std;

string getFilesize(char *path)
{
    struct stat attr;
    stat(path,&attr);
    string s;
    s = ctime(&attr.st_size);
    return s;
}
int main()
{
    string S;  
    
    S = getFilesize("one.txt");
    cout << S;
    return 0;
}