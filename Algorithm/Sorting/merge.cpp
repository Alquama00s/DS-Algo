#include <iostream>
#include <vector>

#include "debug.h"
using namespace std;
void merge(vector<int> &data, int l, int mid, int r) {
    int a = 0;
    int b = 0;
    int i=l;
    vector<int> temp(data.begin() + l, data.begin() + mid+1),
        temp1(data.begin() + mid + 1, data.begin() + r+1);
    while (a <temp.size()&&b<temp1.size()) {
        if (temp[a] < temp1[b]) {
            data[i]=temp[a];
            a++;
        } else {
            data[i]=temp1[b];
            b++;
        }
        i++;
    }
    if (a < temp.size()) {
        while (a <temp.size()) {
            data[i]=temp[a];
            a++;
            i++;
        }
    }
    if (b <temp1.size()) {
        while (b <temp1.size()) {
            data[i]=temp1[b];
            b++;
            i++;
        }
    }
}
void mergeSort(vector<int> &data, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(data, l, mid);
        mergeSort(data, mid + 1, r);
        merge(data, l, mid, r);
    }
}
int main() {
    vector<int> data;
    int n, temp;
    cout << "enter the no. of data\n";
    cin >> n;
    cout << "enter space separated integer\n";
    for (size_t i = 0; i < n; i++) {
        cin >> temp;
        data.push_back(temp);
    }
    mergeSort(data, 0, data.size() - 1);
    print(data);
    return 0;
}