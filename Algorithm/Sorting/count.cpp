#include <iostream>
#include <vector>

#include "debug.h"
using namespace std;
int main() {
    vector<int> data;
    int n, temp,max=0;
    cout << "enter the no. of data\n";
    cin >> n;
    cout << "enter space separated integer\n";
    for (size_t i = 0; i < n; i++) {
        cin >> temp;
        if(temp>max){
            max=temp;
        }
        data.push_back(temp);
    }
    vector<int> pos(max+1,0);
    for (size_t i = 0; i < n; i++)
    {
        pos[data[i]]++;
    }
    for (size_t i = 1; i <= max; i++)
    {
        pos[i]=pos[i-1]+pos[i];
    }
    vector<int> res(n,0);
    for (size_t i = 0; i < n; i++)
    {
        pos[data[i]]--;
        res[pos[data[i]]]=data[i];
    }
    print(res);
    return 0;
}