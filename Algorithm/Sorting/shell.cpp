#include <iostream>
#include <vector>

#include "debug.h"
using namespace std;
int main() {
    vector<int> data;
    int n, temp, k;
    cout << "enter the no. of data or enter -1 for auto mode\n";
    cin >> n;
    cout << "enter space separated integer\n";
    if (n != -1) {
        for (size_t i = 0; i < n; i++) {
            cin >> temp;
            data.push_back(temp);
        }
        cout << "enter the velue of k\n";
        cin >> k;
    } else {
        for (size_t i = 0; i < 100; i++) {
            data.push_back(i + 1);
        }
        k = 40;
    }
    cout << "unsorted: ";
    print(data);
    while (k != 0) {
        for (size_t m = 0; m < k; m++) {
            for (size_t i = m; i < n; i += k) {
                temp = data[i];
                int j;
                for (j = i - k; j >= 0; j -= k) {
                    if (data[j] > temp) {
                        data[j + k] = data[j];
                    } else {
                        break;
                    }
                }
                data[j + k] = temp;
            }
        }

        k--;
        print(data);
    }
    return 0;
}