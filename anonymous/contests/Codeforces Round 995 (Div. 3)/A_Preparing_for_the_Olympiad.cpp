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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0; i < n-1; i++)
        {
            if(a[i]>b[i+1])
            {
                ans+=(a[i]-b[i+1]);
            }
        }
        ans+=a[n-1];
        cout<<ans<<endl;
    }
}