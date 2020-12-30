#include<string>
#include<iostream>
#include<functional>
using namespace std;
class a{
    string ab(string b){
    return b;}
    string (a::*def)(string);
    void somefunc(){
        def=&ab;
        cout<<(a::*def)("kjjk");
    }

};
