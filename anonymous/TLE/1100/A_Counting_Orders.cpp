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
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(b, b + n);
        // for(auto item : a){
        //     cout << item << " ";
        // }
        // cout << "\n";
        // for(auto item : b){
        //     cout << item << " ";
        // }
        // cout << "\n";
        
        int j = 0;
        bool ans = true;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (b[i] >= a[j] && j < n)
            {
                if(i!=n-1 && j==n-1){
                    ans = false;
                    break;
                }
                j++;
            }
            v[i] = n - j;
            if(ans == false){
                break;
            }
        }
        // for(auto item : v){
        //     cout << item << " ";
        // }
        // cout << "\n";
        
        if(ans){
            ll ans = 1;
            int i = 0;
            for(int x=n-1; x>=0; x--){
                ans = (ans*(v[x]-i))%1000000007;
                i++;
            }
            cout<<ans<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}