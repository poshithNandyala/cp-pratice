#include <bits/stdc++.h>

using namespace std;
int main()
{
    int tt = 1;
    ;
    cin >> tt;
    ;
    while (tt--)
    {
        int n, q;
        cin >> n;
        vector<int> a(n), s(n);
        for (int &i : a)
            cin >> i;
        s[n - 1] = n;
        for (int i = n - 2; i >= 0; i--)
            s[i] = (a[i] == a[i + 1] ? s[i + 1] : i + 1);
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            if (s[l] > r)
                cout << -1 << ' ' << -1 << '\n';
            else
                cout << l + 1 << ' ' << 1 + s[l] << '\n';
        }
    }
    return 0;
}