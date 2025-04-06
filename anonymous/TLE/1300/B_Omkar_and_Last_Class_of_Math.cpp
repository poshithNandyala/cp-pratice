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
        if (n % 2 == 0)
        {
            cout << n / 2 << " " << n / 2 << endl;
        }
        else
        {
            int ans = 1;
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    ans = n / i;
                    break;
                }
            }
            cout << ans << " " << n - ans << endl;
        }
    }
}