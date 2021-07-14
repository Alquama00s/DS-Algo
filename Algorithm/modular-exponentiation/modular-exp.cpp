#include <bits/stdc++.h>

#include <iostream>
#define MOD 1000000009
typedef unsigned long long ull;
using namespace std;
ull mod_exp(ull b, bitset<32> bit_str_n) {
    ull ans = 1;
    ull factor = b % MOD;
    string bitset_ = bit_str_n.to_string();
    for (int i = bitset_.size() - 1; i >= 0; i--) {
        if (bitset_[i] == '1') ans = (ans * factor) % MOD;
        factor = (factor * factor) % MOD;
    }

    return ans;
}

int main() {
    ull b;
    int n;
    cin >> b >> n;
    bitset<32> bit(n);
    cout << mod_exp(b, bit);

    return 0;
}