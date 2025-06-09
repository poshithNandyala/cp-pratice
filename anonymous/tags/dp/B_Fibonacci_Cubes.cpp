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
        int f[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
        ll a = f[n] + f[n - 1];
        ll b = f[n], c = f[n];
        // cout<<a<<" "<<b<<" "<<c<<endl;
        int aa[3];
        while (m--)
        {
            cin >> aa[0] >> aa[1] >> aa[2];
            sort(aa, aa + 3);

            // cout<<aa[0]<<" "<<aa[1]<<" "<<aa[2]<<endl;
            if(aa[2]>=a && aa[1]>=b && aa[0]>=c){
                cout << 1;
            }
            else{
                cout << 0;
            }

        }
        cout << endl;
    }
}