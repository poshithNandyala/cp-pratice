#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

bool prime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int32_t main() {
    fastio
    int t = 1;
    while (t--) {
        int n;
        cin >> n;

        for(int m = 1; m <= 1000; m++){
            if(!prime(n * m + 1)){
                cout << m << endl;
                break;
            }
        }
    }
}