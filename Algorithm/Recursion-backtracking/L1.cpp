/*****************************************************************************
 * Problem link: https://www.hackerrank.com/challenges/the-power-sum/problem *
 * type : Recursion & Backtracking                                           *
 *****************************************************************************/
#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<set>
using namespace std;
void print(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}
vector<int> lis;
set<vector<int>,greater<vector<int>>> s;
void powerSum(int X, int N,int d=1) {
    int a=accumulate(lis.begin(),lis.end(),0);
    if(d>X+1 || a>X){
        return;
    }
    if(a==X){
        s.insert(lis);
    }
    lis.push_back(pow(d,N));
    if(lis[lis.size()-1]==99){
        cout<<d;
    }
    powerSum(X,N,d+1);
    lis.pop_back();
    powerSum(X,N,d+1);
}
int main(){
    int a,b;
    cin>>a>>b; 
    powerSum(a,b);
    cout<<s.size();
    set<vector<int>, greater<vector<int>> >::iterator itr;
    for (itr = s.begin(); 
         itr != s.end(); ++itr) 
    {
        print(*itr);
        cout<< "\n";
    }
    cout << endl;
    return 0;
}