#include<iostream>
#include<vector>
#define ll long long
using namespace std;
void print(vector<vector<int>> a){
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < a[i].size(); j++)
        {
            cout<<a[i][j]<<" ";
        }
        
       cout<<"\n"; 
    }cout<<"\n"<<endl;
    
}
void print(vector<vector<bool>> a){
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < a[i].size(); j++)
        {
            cout<<a[i][j]<<" ";
        }
        
       cout<<"\n"; 
    }cout<<"\n"<<endl;
    
}
void print(vector<vector<ll>> a){
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < a[i].size(); j++)
        {
            cout<<a[i][j]<<" ";
        }
        
       cout<<"\n"; 
    }cout<<"\n"<<endl;
    
}