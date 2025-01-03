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
        int a[n];
        map<int, int> h;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            h[a[i]]++;
        }
        int val = 1;
        for(auto item : h){
            val = max(val, item.second);
        }
        int rem = n - val, ans = 0;
        // cout << "val" << val << "rem" << rem << endl;
        while (rem > 0)
        {
            ans++;
            ans += min(val, rem);
            rem -= val;
            val <<= 1;
        }
        cout << ans << endl;
    }
}