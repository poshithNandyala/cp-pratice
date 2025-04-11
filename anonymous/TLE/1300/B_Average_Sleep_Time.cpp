#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio;
    double n, k;
    cin >> n >> k;
    vector<double> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i > 0)
        {
            a[i] += a[i - 1];
        }
    }
    double ans = 0;
    int j = k;
    // for(auto item : a){
    //     cout << item << " ";
    // }
    // cout << "\n";
    
    for (int i = 0; j <= n; i++)
    {
        ans += (a[j] - a[i]);
        j++;
    }
    // cout << ans << endl;
    cout << fixed << setprecision(10) << ans / (n-k+1) << endl;
}