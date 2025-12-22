#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

void rec(int st, int mi, int en, int num) {
    if (num == 0) return;
    rec(st, en, mi, num - 1);
    cout << st << " " << en << endl;
    rec(mi, st, en, num - 1);
}

int32_t main() {
    fastio
        int n;
    cin >> n;
    cout << (1LL << n) - 1 << endl;
    rec(1, 2, 3, n);
}
