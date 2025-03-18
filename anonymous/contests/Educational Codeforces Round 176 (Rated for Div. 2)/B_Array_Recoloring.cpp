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
        ll n, k;
        cin >> n >> k;
        ll arr[n], a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            a[i] = arr[i];
        }
        sort(arr, arr + n, greater<ll>());
        bool start = false, end = false;
        ll sum = 0;
        k += 1;
        for (int i = 1; i <= k; i++)
        {
            sum += arr[i - 1];
        }
        if (find(arr, arr + k, a[0]) != arr + k)
        {
            start = true;
        }
        if (find(arr, arr + k, a[n - 1]) != arr + k)
        {
            end = true;
        }
        // cout << "start = " << start << " end = " << end << endl;
        if ((k != 2) || (start || end))
        {
            cout << sum << endl;
            continue;
        }
        // cout << "yes" << endl;
        cout << arr[0] + max(a[0], a[n - 1]) << endl;
    }
}