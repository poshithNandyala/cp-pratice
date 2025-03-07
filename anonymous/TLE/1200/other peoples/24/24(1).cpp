#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = count(begin(s), end(s), '0');
    if (cnt & 1 && cnt > 1)
        cout << "ALICE\n";
    else
        cout << "BOB\n";
}

signed main()
{
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
}