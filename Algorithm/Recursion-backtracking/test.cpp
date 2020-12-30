#include<vector>
#include<string>
#include<iostream>
using namespace std;
void encrypt(string a){
    int n=a.length();
    vector<int> W(n,0);
    for (size_t i = 0; i < n; i++){
        if((a[i]<'a') || (a[i]>'z')){
            return ;
        }
        for (size_t j = 0; j < n; j++){
            if (a[i]>a[j]){
                W[i]++;
            }
            
        }
        for (size_t j = i; j < n; j++){
            if ((i!=j) && (a[i]==a[j])){
                return ;
            }
            W[i]=W[i]+a[j]-'a';
        }
        //W[i]%=10;
        
    }
    cout<<a<<"\n";
    for (size_t i = 0; i < W.size(); i++)
    {
        cout<<W[i]<<" ";
    }
   cout<<"\n"; 
}
int main(){
    string a;
    cin>>a;
    encrypt(a);
    // int t='z'-'a';
    // cout<<t;
    return 0;
}