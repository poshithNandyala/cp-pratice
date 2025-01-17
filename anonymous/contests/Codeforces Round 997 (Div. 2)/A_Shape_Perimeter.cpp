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
        int n, m;
        cin >> n >> m;
        int x[n+1], y[n+1];
        x[0]=0,y[0]=0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
            x[i]+=x[i-1];
            y[i]+=y[i-1];
        }
        int x1=x[1], y1=y[1];
        x[n] += m;
        y[n] += m;
        int xlen = x[n] - x1;
        int ylen = y[n] - y1;
        cout<< xlen*2 + ylen*2<<endl;
    }
}