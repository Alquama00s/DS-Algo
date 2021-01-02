/*infix expression evaluation*/
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<functional>
using namespace std;
class Infixstack{
    stack<string> s;
    //float counter,counter2;
    static string InfixEval(string va1,string va2,string o){
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
    static string PostFix(string va1,string va2,string o){
        return (va2+" "+va1+" "+o);
    }
    static string PreFix(string va1,string va2,string o){
        return (o+" "+va2+" "+va1);
    }
    bool isOperator(string s){
        if(s=="*"||s=="/"||s=="+"||s=="-"){
            return true;
        }
        return false;
    }
    bool PreCond(string a){
        if(isOperator(a)){
            return false;
        }
        if((s.size()>0)&&(!isOperator(s.top()))){
            return true;
        }
        return false;
    }
    static string PreEval(string va1,string va2,string va3){
        float v1 ,v2;
        v1=stof(va2);
        v2=stof(va1);
        if(va3=="*"){
            v1=v1*v2;
        }else if(va3=="/"){
            v1=v1/v2;
        }else if(va3=="-"){
            v1=v1-v2;
        }else{
            v1=v1+v2;
        }
       return (to_string(v1));
    }
    string (*Eval)(string,string,string);
    void Ipush(string a){
        cout<<a<<"\n";
        string s1="",s2="",s3="";
        if(!PreCond(a)){
            s.push(a);
        }else{
            s1=a;
            s2=s.top();
            s.pop();
            s3=s.top();
            s.pop();
            s1=(*Eval)(s1,s2,s3);
            Ipush(s1);
        }
    }
    string Pusher(string str){
        string word;
        istringstream st(str);
        while(st >> word){
            Ipush(word);
        }
        return s.top();
    }
    public:
    // float evaluate(string s){
    //     Eval=&InfixEval;
    //     return stof(Pusher(s));
    // }
    float Prevaluate(string s){
        Eval=&PreEval;
        return stof(Pusher(s));
    }
    // string toPrefix(string s){
    //     Eval=&PreFix;
    //     return Pusher(s);   
    // }
    // string toPostfix(string s){
    //     Eval=&PostFix;
    //     return Pusher(s);   
    // }

};
int main(){
    
    Infixstack s;
    string b,word;
    getline(cin,b);
    cout<<s.Prevaluate(b)<<" ans:\n";
    return 0;
}