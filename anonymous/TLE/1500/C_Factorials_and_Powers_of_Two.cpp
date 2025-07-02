#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

vector<ll> powerful;
ll k;

ll rec(ll i, ll n)
{
    if (n < 0)
    {
        return k + 1;
    }
    if (i == k)
    {
        return __builtin_popcountll(n);
    }

    ll ans = rec(i + 1, n);
    if (powerful[i] <= n)
    {
        ans = min(ans, rec(i + 1, n - powerful[i]) + 1);
    }
    return ans;
}
int main()
{
    fastio
    ll maxv = 1e12;
    // ll i = 1;
    // while (i <= maxv)
    // {
    //     powerful.push_back(i);
    //     i *= 2;
    // }
    k = 1;
    ll curr = 2;
    while (k <= maxv)
    {
        powerful.push_back(k);
        k *= curr;
        curr++;
    }
    sort(powerful.begin(), powerful.end());
    k = powerful.size();
    // for(auto item : powerful){
    //     cout << item << " ";
    // }
    // cout << "\n";

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << rec(0, n) << endl;
    }
}