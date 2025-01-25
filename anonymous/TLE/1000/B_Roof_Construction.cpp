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
        if (n == 2)
        {
            cout << 0 << " " << 1;
        }
        else
        {
            n -= 1;
            int mx = 0, va = 1;
            for (int i = 0; i < 32; i++)
            {
                if ((1 << i) & n)
                {
                    mx = va;
                }
                va *= 2;
            }
            for (int i = n; i >= mx; i--)
            {
                cout << i << " ";
            }
            cout << 0 << " ";
            for (int i = 1; i < mx; i++)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}