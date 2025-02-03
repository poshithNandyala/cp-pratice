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
        map<int, int> mpa, mpb;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mpa[a[i]]++;
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
            mpb[b[i]]++;
        }
        bool ans = false;
        if(mpa.size()>=2 && mpb.size()>=2){
            ans = true;
        }
        if(mpa.size()>=3 || mpb.size()>=3){
            ans = true;
        }
        if(ans){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}