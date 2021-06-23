#include <iostream>
#include <vector>

#include "debug.h"
using namespace std;
int partition(vector<int> &data, int l, int r) {
    int pi = data[r];
    int i = l - 1, temp;
    for (size_t j = l; j < r; j++) {
        if (data[j] < pi) {
            i++;
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    i++;
    temp = data[i];
    data[i] = data[r];
    data[r] = temp;
    return i;
}
void quickSort(vector<int> &data, int l, int r) {
    if (l < r) {
        int pi_ind = partition(data, l, r);
        quickSort(data, l, pi_ind - 1);
        quickSort(data, pi_ind + 1, r);
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
    quickSort(data, 0, data.size() - 1);
    print(data);
    return 0;
}