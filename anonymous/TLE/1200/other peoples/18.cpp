#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int tc, n, x[MAX], ans;
bool st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        st = 1;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x[i];
            if (i > 1)
                st &= x[i] >= x[i - 1];
        }
        if (st)
        {
            cout << "0\n";
            continue;
        }
        if (x[n - 1] > x[n] || x[n] < 0)
            cout << "-1\n";
        else
        {
            cout << n - 2 << "\n";
            for (int i = 1; i <= n - 2; ++i)
                cout << i << " " << n - 1 << " " << n << '\n';
        }
    }
    return 0;
}