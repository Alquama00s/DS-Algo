#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
string InfixEval(string va1,string va2,string o){
        float v1 ,v2;
        v1=stof(va1);
        v2=stof(va2);
        if(o=="*"){
            v1=v2*v1;
        }else if(o=="/"){
            v1=v2/v1;
        }else if(o=="-"){
            v1=v2-v1;
        }else{
            v1=v2+v1;
        }
       return (to_string(v1));
}
int main(){
    stack<string> s;
    string b,word,o,v1,v2;;
    getline(cin,b);
    istringstream st(b);
    while(st >> word){
        if(word!=")"){
            s.push(word);
        }else{
            v1=s.top();
            s.pop();
            o=s.top();
            s.pop();
            v2=s.top();
            s.pop();
            s.pop(); //( -> bracket pop
            v1=InfixEval(v1,v2,o);
            s.push(v1);
        }
    }
    cout<<s.top();
    return 0;
}