/*infix expression evaluation*/
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<functional>
using namespace std;
class Infixstack{
    stack<string> s;
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
    string (*Eval)(string,string,string);
    void Ipush(string a){
        string o,v1,v2;
        if(a!=")"){
            s.push(a);
        }else{
            v1=s.top();
            s.pop();
            o=s.top();
            s.pop();
            v2=s.top();
            s.pop();
            s.pop(); //( -> bracket pop
            v1=(*Eval)(v1,v2,o);
            s.push(v1);
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
    float evaluate(string s){
        Eval=&InfixEval;
        return stof(Pusher(s));
    }
    string toPrefix(string s){
        Eval=&PreFix;
        return Pusher(s);   
    }
    string toPostfix(string s){
        Eval=&PostFix;
        return Pusher(s);   
    }

};
int main(){
    
    Infixstack s;
    string b,word;
    getline(cin,b);
    cout<<s.evaluate(b)<<"\n";
    cout<<s.toPostfix(b)<<"\n";
    cout<<s.toPrefix(b)<<"\n";
    return 0;
}