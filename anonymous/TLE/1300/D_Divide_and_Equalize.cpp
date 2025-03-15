#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

const int MAX = 1000000;
vector<bool> isprime(MAX + 1, true);
vector<int> hp(MAX + 1, 0);

void sieve()
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        if (isprime[i])
        {
            hp[i] = i;
            for (int j = 2 * i; j <= MAX; j += i)
            {
                isprime[j] = false;
                hp[j] = i;
            }
        }
    }
}

int main()
{
    fastio
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            while (a[i] > 1)
            {
                int primefactor = hp[a[i]];
                while (a[i] % primefactor == 0)
                {
                    a[i] /= primefactor;
                    mp[primefactor]++;
                }
            }
        }
        bool ans = true;
        for (auto i : mp)
        {
            if (i.second % n)
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}