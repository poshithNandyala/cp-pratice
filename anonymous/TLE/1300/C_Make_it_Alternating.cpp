#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define ll long long

long long nPr(int n, int r)
{
    if (r > n)
        return 0;
    long long result = 1;
    for (int i = 0; i < r; i++)
    {
        result = result * (n - i) % 998244353;
    }
    return result;
}

long long power(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b)
    {
        if (b % 2)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

long long modInverse(long long a, long long mod)
{
    return power(a, mod - 2, mod);
}

long long nCr(int n, int r)
{
    if (r > n)
        return 0;
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i) % 998244353;
        res = res * modInverse(i + 1, 998244353) % 998244353;
    }
    return res;
}

int main()
{
    fastio

        int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> s;
        n = s.size();
        vector<int> v;
        int c = 1;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                c++;
            }
            else
            {
                if (c >= 2)
                {
                    v.push_back(c);
                }
                c = 1;
            }
        }
        if (c >= 2)
        {
            v.push_back(c);
        }

        ll ans1 = 0, ans2 = 1;
        for (auto i : v)
        {
            ans1 += (i - 1);
            ans2 = (ans2 * nCr(i, i - 1)) % 998244353;
        }
        int i = v.size();
        if (i)
        {
            ans2 = (ans2 * nPr(ans1, ans1 - 1)) % 998244353;
        }

        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}