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
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int m = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] - a[i] > m)
            {
                m = a[i + 1] - a[i];
            }
        }
        if(2*(x-a[n-1])>m)
        {
            cout<<2*(x-a[n-1])<<endl;
        }
        else
        {
            cout<<m<<endl;
        }
    
    }
}