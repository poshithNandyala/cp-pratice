#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int cnt[N];
void run()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    bool flag = 0;
    for (int i = 0; i < s.size(); i++)
        cnt[i] = (i ? cnt[i - 1] : 0) + (s[i] == '1');
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (!flag && s[i] == t[i] || flag && s[i] != t[i])
            continue;
        if (cnt[i] * 2 == i + 1)
            flag ^= 1;
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        run();
    return 0;
}
