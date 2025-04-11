#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio

        string s;
    cin >> s;
    int n = s.size();
    map<int, int> front, back;
    int cf = 0, cb = 0,cff=0,cbb=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'v')
        {
            cf++;
        }
        if (s[i] == 'o')
        {
            if(i>0 && s[i-1] == 'v')
            {
                cff+=(cf-1);
            }
            front[i] = cff;
            if(i<n-1 && s[i+1] == 'v')
            {
                cf = 0;
            }
        }
        if (s[n - i - 1] == 'v')
        {
            cb++;
        }
        if (s[n - i - 1] == 'o')
        {
            if(i<n && s[n-i] == 'v')
            {
                cbb+=(cb-1);
            }
            back[n - i - 1] = cbb;
            if(i<n-1 && s[n - i - 2] == 'v')
            {
                cb = 0;
            }
        }
    }
    ll ans = 0;
    // for(auto item : front){
    //     cout << item.first << " " << item.second << endl;
    // }
    // cout << "\n";
    // for(auto item : back){
    //     cout << item.first << " " << item.second << endl;
    // }
    // cout << "\n";
    
    for (auto it : front)
    {
        int i = it.first;
        ans += (front[i] * 1LL * back[i]);
    }
    cout << ans << endl;
}
