#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        int l = 0, r = n - 1;
        while (l < r && v[l] == v[r])
        {
            l++, r--;
        }
        auto good = [&](int ch) -> bool
        {
            int i = 0, j = n - 1;
            while (i <= j)
            {
                if (v[i] != v[j])
                {
                    if (v[i] == ch)
                        i++;
                    else if (v[j] == ch)
                        j--;
                    else
                    {
                        return false;
                    }
                }
                else
                    i++, j--;
            }
            return true;
        };
        if (l < r)
        {
            if (good(v[l]) || good(v[r]))
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
        else
            cout << "YES" << "\n";
    }
}