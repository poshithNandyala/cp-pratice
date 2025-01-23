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
        int n,k;
        cin >> n>>k;
        string s;
        cin >> s;
        int a[n+1] = {};
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'W')
            {
                a[i+1] = 1;
            }
        }
        for(int i=1;i<=n;i++){
            a[i] += a[i - 1];
        }
     
        
        int ans = 100000000;
        for (int i = k; i <= n; i++)
        {
            ans = min(ans, a[i] - a[i - k]);
        }
        cout << ans << endl;
    }
}