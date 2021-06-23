//incomplete
//maximum sub array problem

#include <bits/stdc++.h>

#include <iostream>
using namespace std;
vector<int> data;
int* find_max_cross(int beg, int mid, int end) {
    int sum = 0, total_left = INT_MIN, total_right = INT_MIN, left_index,
        right_index;
    for (int i = mid; i >= beg; i--) {
        /* code */
        sum += data[i];
        if (sum > total_left) {
            total_left = sum;
            left_index = i;
        }
    }
    sum = 0;
    for (int i = mid; i < end; i++) {
        /* code */
        sum += data[i];
        if (sum > total_right) {
            total_right = sum;
            right_index = i;
        }
    }
    int ans[3] = {right_index, left_index, total_right + total_left};
    return ans;
}
int* find_max(int beg, int end) {
    if (beg == end) {
        int ans[3] = {beg, end, data[beg]};
        return ans;
    }
    int mid = (beg + end) / 2;
    int* rt = find_max(beg, mid);
    int* lt = find_max(mid+1, end);
    int* crs = find_max_cross(beg, mid, end);
    if (crs[2] > lt[2] && crs[2] > rt[2]) {
        return crs;
    } else if (lt[2] > rt[2] && lt[2] > crs[2]) {
        return lt;
    } else {
        return rt;
    }
}
int main() {
    //vector<int> data;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        data.push_back(temp);
    }
    int* ans=find_max(0,n-1);
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
    /*for (int i = ans[0]; i <=ans[2]; i++)
    {
        cout<<data[i];
    }*/
    
    return 0;
}