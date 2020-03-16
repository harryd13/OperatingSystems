#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <iostream>

using namespace std;

size_t getFilesize(const string& filename)
{
    struct stat st;
    if(stat(filename.c_str(),&st) != 0){
        return 0;
    }
    return st.st_size;
}
size_t getFilecreation(const string& filename)
{
    struct stat st;
    if(stat(filename.c_str(),&st) != 0){
        return 0;
    }
    return st.st_size;
}
int main()
{
    int t = getFilesize("three.txt");
    cout << t;
    return 0;
}