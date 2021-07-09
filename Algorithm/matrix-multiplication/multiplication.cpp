//incomplete
#include <bits/stdc++.h>

#include "debug.h"
using namespace std;
vector<vector<int>> a, b, main_ans;
vector<vector<int>> mat_add(vector<vector<int>> a, vector<vector<int>> b,
                            int add = 1) {
    vector<vector<int>> ans(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            ans[i][j] = a[i][j] + add * b[i][j];
        }
    }
    return ans;
}
vector<vector<int>> strassen(pair<int, int> init1, pair<int, int> init2,
                             int length) {
    int size = length-1;
    if (size <= 2) {
        vector<vector<int>> ans(2, vector<int>(2, 0));
        ans[0][0] = a[init1.first][init1.second] * b[init2.first][init2.second] + a[init1.first][init1.second+size] * b[init2.first+size][init2.second];
        ans[0][1] = a[init1.first][init1.second] * b[init2.first][init2.second+size] + a[init1.first][init1.second+size] * b[init2.first+size][init2.second+size];
        ans[1][0] = a[init1.first+size][init1.second] * b[init2.first][init2.second] + a[init1.first+size][init1.second+size] * b[init2.first][init2.second+size];
        ans[1][1] = a[init1.first+size][init1.second] * b[init2.first][init2.second+size] + a[init1.first+size][init1.second+size] * b[init2.first+size][init2.second+size];
        return ans;
    } else {
        vector<vector<int>> a11, a12, a21, a22;
        size = length / 2;
        a11 = mat_add(
            strassen(init1, init2, size),
            strassen(pair<int, int>(init1.first + size, init1.second),
                     pair<int, int>(init2.first, init2.second + size), size));
        a12 = mat_add(
            strassen(init1, pair<int, int>(init2.first+size, init2.second), size),
            strassen(pair<int, int>(init1.first, init1.second+size),
                     pair<int, int>(init2.first+size, init2.second + size), size));
        a21 = mat_add(
            strassen(pair<int, int>(init1.first , init1.second+size), init2, size),
            strassen(pair<int, int>(init1.first +size, init1.second+size),
                     pair<int, int>(init2.first, init2.second+size ), size));
        a22 = mat_add(
            strassen(pair<int, int>(init1.first , init1.second+size),
                     pair<int, int>(init2.first+size, init2.second ), size),
            strassen(pair<int, int>(init1.first +size, init1.second+size),
                     pair<int, int>(init2.first+size, init2.second +size), size));
    
        main_ans.clear();
        print(a11);print(a12);print(a21);print(a22);
        for(int i=0;i<size;i++){
            main_ans.push_back(vector<int>(2*size,0));
            for(int j=0;j<2*size;j++){
                if(j<size){
                    main_ans[i][j]=a11[i][j];
                }else{
                    main_ans[i][j]=a12[i][j-size];
                }
            }
        }
        for(int i=0;i<size;i++){
            main_ans.push_back(vector<int>(2*size,0));
            for(int j=0;j<2*size;j++){
                if(j<size){
                    main_ans[i+size][j]=a21[i][j];
                }else{
                    main_ans[i+size][j]=a22[i][j-size];
                }
            }
        }
        return main_ans;
    }
}

vector<vector<int>> multiply() {
    if (a[0].size() == b.size()) {
        // making the matrix square
        int r1 = a.size();
        int c1 = a[0].size();  //=r2
        int c2 = b[0].size();
        int _max = max(r1, max(c1, c2));
        cout << _max << "max\n";
        _max = pow(2, ceil(log2(_max)));
        cout << _max << "max\n";
        if (r1 < _max) {
            vector<int> temp(_max, 0);
            for (int i = r1; i < _max; i++) {
                a.push_back(temp);
            }
        }
        if (c1 < _max) {
            vector<int> temp(_max - c1, 0);
            for (int i = 0; i < r1; i++) {
                a[i].insert(a[i].end(), temp.begin(), temp.end());
            }
            vector<int> temp2(_max, 0);
            for (int i = c1; i < _max; i++) {
                b.push_back(temp2);
            }
        }
        if (c2 < _max) {
            vector<int> temp(_max, 0);
            for (int i = c2; i < _max; i++) {
                b.push_back(temp);
            }
        }
        return strassen(pair<int, int>(0, 0), pair<int, int>(0, 0), _max);
    } else {
        cerr << "error";
        return main_ans;
    }
}
int main() {
    int r1, c1, r2, c2, t, temp;
    cin >> t;
    while (t-- > 0) {
        a.clear();
        b.clear();
        main_ans.clear();
        cin >> r1 >> c1 >> r2 >> c2;
        for (int i = 0; i < r1; i++) {
            a.push_back(vector<int>());
            for (int j = 0; j < c1; j++) {
                cin >> temp;
                a[i].push_back(temp);
            }
        }
        for (int i = 0; i < r2; i++) {
            b.push_back(vector<int>());
            for (int j = 0; j < c2; j++) {
                cin >> temp;
                b[i].push_back(temp);
            }
        }
        main_ans = multiply();
        print(main_ans);
    }

    return 0;
}