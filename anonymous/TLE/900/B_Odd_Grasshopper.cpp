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
        ll x, n;
        cin >> x >> n;
        ll mag;
        if (n % 4 == 0)
        {
            mag = 0;
        }
        else if (n % 4 == 1)
        {
            mag = -1 * n;
        }
        else if (n % 4 == 2)
        {
            mag = 1;
        }
        else
        {
            mag = n + 1;
        }
        if(x%2){
            mag *= -1;
        }
        
        cout << x + mag << endl;
    }
}