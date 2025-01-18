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
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > k)
            {
                a[i] = (a[i] % k) ? a[i] % k : k;
            }
            mp[a[i]]++;
        }
        // for (auto item : mp)
        // {
        //     cout << item.first << " " << item.second << endl;
        // }
        // cout << "\n";

        map<int, int> mps;

        int x = 1;
        for (auto it = prev(mp.end()); it != mp.begin(); it--)
        {
            auto y = *it;
            mps[y.first] = x;
            x += (y.second);
        }
        mps[mp.begin()->first] = x;
        // for(auto item : mps){
        //     cout << item.first << " "<<item.second << endl;
        // }
        // cout << "\n";

        vector<int> v(n + 1);
        for (int i = 0; i < n; i++)
        {
            // cout << mps[a[i]]++ << endl;
            int x = mps[a[i]]++;
            // cout << x << " ";
            v[x] = i + 1;
        }
        // cout << "\n";
        for (int i = 1; i <= n; i++)
        {
            // if(v[i] ==0){
            //     cout<<n<<0<<k;
            //     for(int j=0; j<n; j++){
            //         cout << a[j] <<0;
            //         }
            //         cout << endl;
            // }
            cout << v[i] << " ";
        }
        cout << endl;
        // cout << "ok" << endl;
    }
}