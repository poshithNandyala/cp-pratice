#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

vector<bool> isPrime;
vector<int> primes;

void sieve(int n) {
    isPrime.assign(n + 1, true);

    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int32_t main() {
    fastio
        sieve(1e6);
        int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (auto it : primes) {
            if(it>n) break;
            int a = it;
            int b = n - it-1;
            int c = __gcd(a, b);
            if(a+b+c==n){
                cout << a << " " << b << " " << c << endl;
                break;
            }
        }

    }
}
