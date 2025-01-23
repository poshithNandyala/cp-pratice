#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int i = 0, j = n - 1;
    int x = 1;
    bool flag = true;
    while (i < j)
    {
        if (x == 0)
        {

            flag = true;
            j--;
            ans++;
            x = 1;
        }
        if (flag)
        {

            x = (a[j] + d - 1) / a[j];

            flag = false;

            if (d % a[j])
            {
                x--;
            }
        }
        else
        {

            x--;
            i++;
        }
    }
    if (x == 0)
    {

        flag = true;
        j--;
        ans++;
    }
    if (n == 1 && a[0] > d)
    {
        ans++;
    }
    cout << ans << endl;
}