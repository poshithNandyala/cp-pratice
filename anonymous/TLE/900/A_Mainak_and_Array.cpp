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
    int x = t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int ans = 0;
        int ma=INT_MIN, mi=INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ma = max(ma, a[i]);
            mi = min(mi, a[i]);
        }
        int i = 0;
        while(i<n-1){
            ans = max(ans, a[i] - a[i + 1]);
            i++;
        }
        int first = a[0], last = a[n - 1];
        ans = max(ans, a[n-1] - a[0]);
        ans = max(ans, a[n - 1] - mi);
        ans = max(ans, ma - a[0]);
        cout << ans << endl;
    }
}