#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

int main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        int n,l,r;
        cin >> n >> l >> r;
        vector<long long> ans;
        for (long long i = 1; i <= n; i++)
        {
            long long k = 1ll * (l + i - 1) / i;
            if (k * i <= r)
                ans.push_back(k * i);
            else
                break;
        }
        if (ans.size() != n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (auto i : ans)
                cout << i << " ";
            cout << endl;
        }
    }
}