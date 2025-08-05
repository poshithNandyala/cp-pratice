#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;   

long long solve(const vector<long long>& a) {
    long long prod = 1;
    for (long long v : a) {
        prod = prod * ((v % MOD + MOD) % MOD + 1) % MOD;
    }
    return (prod - 1 + MOD) % MOD; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector <long long> a;
    int c = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == 'a') {
            c++;
        }
        if (s[i] == 'b' && c) {
            a.push_back(c);
            c = 0;
        }
    }
    if (c) a.push_back(c);
    // for(auto item : a){
    //     cout << item << " ";
    // }
    // cout << "\n";
    
    cout << solve(a) << "\n";
}
