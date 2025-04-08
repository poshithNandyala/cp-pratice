#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll generateY(int x, int k)
{
    ll y = 0;
    for (int i = 0; i < k; i++)
    {
        y = y * 10 + x;
    }
    return y;
}

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;
        if (k >= 2 && x>=10)
        {
            cout << "NO" << endl;
            continue;
        }
        if (isPrime(generateY(x, k)))
        {
            cout <<  "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        // cout<<cnt+ans-1<<endl;
    }
}
