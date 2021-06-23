#include<iostream>
#include<vector>
#include "debug.h"
using namespace std;
int main(){
    vector<int> data;
    int n,temp,min;
    cout<<"enter the no. of data\n";
    cin>>n;
    cout<<"enter space separated integer\n";
    for (size_t i = 0; i < n; i++)
    {
        cin>>temp;
        data.push_back(temp);
    }
    for (size_t i = 0; i < n-1; i++)
    {
        //find minima
        min=i;
        for (size_t j = i+1; j < n; j++)
        {
            if(data[j]<data[min]){
                min=j;
            }
        }
        //swap
        temp=data[i];
        data[i]=data[min];
        data[min]=temp;
        print(data);
    }
    
    return 0;
}