#include<iostream>
#include<vector>
#include "debug.h"
using namespace std;
int main(){
    vector<int> data;
    int n,temp;
    cout<<"enter the no. of data\n";
    cin>>n;
    cout<<"enter space separated integer\n";
    for (size_t i = 0; i < n; i++)
    {
        cin>>temp;
        data.push_back(temp);
    }
    n--;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n-i; j++)
        {
            if(data[j]>data[j+1]){
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
        print(data);       
    }
    
    return 0;
}