#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    auto dfs = [&](auto self, string w, int len) -> bool
    {
        if (w.size() == len)
        {
            if (s.find(w) == -1)
            {
                cout << w << endl;
                return true;
            }
            return false;
        }
        for (int i = 0; i < 26; i++)
        {
            if (self(self, w + char(i + 'a'), len))
                return true;
        }
        return false;
    };
    for (int i = 1; i <= n; i++)
    {
        if (dfs(dfs, "", i))
            return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}