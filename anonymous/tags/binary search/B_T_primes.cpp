#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

void seive(vector<bool>& is_prime) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < is_prime.size(); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }
}
int square_root(int x) {
    int left = 0, right = 1e9, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid * mid <= x) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

int32_t main() {
    fastio

        vector<bool> is_prime(10000001, true);
    seive(is_prime);
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        int y = square_root(x);
        if ((y * y == x) && (is_prime[y])) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
