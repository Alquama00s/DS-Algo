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
    for (size_t i = 1; i < n; i++)
    {
        temp=data[i];
        int j;
        for (j = i-1; j >=0; j--)
        {
            if(data[j]>temp){
                data[j+1]=data[j];
            }else{
                break;
            }
        }
        data[j+1]=temp;
        print(data);
    }
    
    return 0;
}