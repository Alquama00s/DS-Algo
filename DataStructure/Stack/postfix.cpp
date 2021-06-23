/*infix expression evaluation*/
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<functional>
using namespace std;
class Infixstack{
    static stack<string> s;
    static bool isOperator(string s){
        if(s=="*"||s=="/"||s=="+"||s=="-"){
            return true;
        }
        return false;
    }
    static bool PostCond(string a){
        return isOperator(a);
    }
    static bool PreCond(string a){
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
    static string PostEval(string va1,string va2,string va3){
        float v1 ,v2;
        v1=stof(va3);
        v2=stof(va2);
        if(va1=="*"){
            v1=v1*v2;
        }else if(va1=="/"){
            v1=v1/v2;
        }else if(va1=="-"){
            v1=v1-v2;
        }else{
            v1=v1+v2;
        }
       return (to_string(v1));
    }
    string (*Eval)(string,string,string);
    bool (*Cond)(string);
    void Ipush(string a){
        string s1="",s2="",s3="";
        if(!PostCond(a)){
            s.push(a);
        }else{
            s1=a;
            s2=s.top();
            s.pop();
            s3=s.top();
            s.pop();
            s1=(*Eval)(s1,s2,s3);
            s.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                push(s1);
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
    float Pevaluate(string s){
        Eval=&PostEval;
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
    cout<<s.Pevaluate(b)<<"ans:\n";
    return 0;
}