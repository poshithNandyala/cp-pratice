#include <bits/stdc++.h>
using namespace std;
#define int long long int

int n;
int ans = 0;
vector<int> v;

int checker(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        if (v[i] == y || (v[i] + i) == (x + y) || (v[i] - i) == (y - x))
            return 0;
    }
    if ((x - 1) >= 0)
    {
        if (v[x - 1] == y - 2 || v[x - 1] == y + 2)
            return 0;
    }
    if ((x - 2) >= 0)
    {
        if (v[x - 2] == y - 1 || v[x - 2] == y + 1)
            return 0;
    }
    return 1;
}

void back_tracking(int level)
{
    if (level == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (checker(level, i))
        {
            v.push_back(i);
            back_tracking(level + 1);
            v.pop_back();
        }
    }
}

void solve()
{
    cin >> n;
    back_tracking(0);
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}
