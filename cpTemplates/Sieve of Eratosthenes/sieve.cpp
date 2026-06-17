#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n = 100;
    sieve(n);

    for (int p : primes) {
        cout << p << " ";
    }
    cout << '\n';
}