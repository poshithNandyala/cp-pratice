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
        string s;

        vector<int> v(n + 1);
        int xor0 = 0, xor1 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                xor0 ^= v[i + 1];
            }
            else
            {
                xor1 ^= v[i + 1];
            }
            v[i + 1] ^= v[i];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int p;
            cin >> p;
            if (p == 1)
            {
                int l, r;
                cin >> l >> r;
                int val = v[r] ^ v[l - 1];
                xor0 ^= val;
                xor1 ^= val;
                continue;
            }
            int x;
            cin >> x;
            if (x)
            {
                cout << xor1 << " ";
            }
            else
            {
                cout << xor0 << " ";
            }
        }
        cout << endl;
    }
}