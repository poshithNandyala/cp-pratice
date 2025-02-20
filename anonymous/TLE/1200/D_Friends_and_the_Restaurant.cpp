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
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            c[i] = (b[i] - a[i]);
        }
        sort(c.begin(), c.end(),greater<int>());
        int i = 0,j=n-1;
        ll ans = 0;
        // for(auto item : c){
        //     cout << item << " ";
        // }
        // cout << "\n";
        
        while(i<j){
            if(c[i]+c[j]>=0){
                i++;
                j--;
                ans++;
            }
            else{
                j--;
            }
        }
        cout<<ans<<endl;
    }
}