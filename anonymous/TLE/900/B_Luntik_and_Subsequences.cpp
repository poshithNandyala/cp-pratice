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
        ll n;
        cin >> n;
        ll a[n];
        ll one = 0, zero = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] == 0){
                zero *= 2;
            }
            else if(a[i] == 1){
                one++;
            }
        }
        cout << one * zero << endl;

    }
}