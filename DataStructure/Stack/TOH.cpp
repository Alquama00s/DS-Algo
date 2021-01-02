#include<iostream>
using namespace std;
void TOH(int n,char I,char F,char A){
    if(n==1){
        cout<<"moving top disk from "<<I<<" to "<<F<<"\n";
    }else{
    TOH(n-1,I,A,F);
    cout<<"move top disk from "<<I<<" to "<<F<<"\n";
    TOH(n-1,A,F,I);
    }
}
int main(){
    TOH(3,'I','F','A');
    return 0;
}