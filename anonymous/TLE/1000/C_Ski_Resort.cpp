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
    // int i = 0;
    while (t--)
    {
        // i++;
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        int c = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= q)
            {
                c++;
            }
            else if (c >= k)
            {
                int mi = c - k + 1;
                ans += (mi * 1LL*(mi + 1)) / 2;
                c = 0;
            }
            else
            {
                c = 0;
            }
            // cout << "c" << c << endl;
        }
        // cout << "c" << c << endl;
        // if(i==34){
        //     cout<<"n"<<n<<"k"<<k<<"q"<<q;
        //     cout << "a";
        //     for(int i=0;i<n;i++){
        //         cout<<a[i]<<"a";
        //     }
        // }
        if (c >= k)
        {
            int mi = c - k + 1;
            ans += (mi *1LL* (mi + 1)) / 2;
        }
        cout << ans << endl;
    }
}
