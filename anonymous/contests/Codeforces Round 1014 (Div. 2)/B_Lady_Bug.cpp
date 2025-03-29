#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int aa = 0, bb = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                if (a[i] == '0')
                    bb++;
                if (b[i] == '0')
                    aa++;
            }
            else
            {
                if (a[i] == '0')
                    aa++;
                if (b[i] == '0')
                    bb++;
            }
        }
        // cout << aa << " " << bb << endl;
        bool ans = false;
        if (n % 2 == 0 && n / 2 <= aa && n / 2 <= bb)
        {
            ans = true;
        }
        if (n % 2 == 1 && (n / 2 + 1) <= aa && (n / 2) <= bb)
        {
            ans = true;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}