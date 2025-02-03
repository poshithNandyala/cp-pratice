#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int a[200001], ans = -1;
bool ans1 = false;

ll caluclate(int n, int h)
{
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < h)
        {
            cnt += (h - a[i]);
        }
        else
        {
            break;
        }
    }
    return cnt;
}
ll binarySearch( int n, int x)
{
    ll left = *min_element(a, a + n);
    ll right = *max_element(a, a + n) + ((x + n - 1) / n);
    ll ans = 0;

    while (left <= right)
    {

        ll mid = left + (right - left) / 2;
        ll total_reduction = 0;

        total_reduction = caluclate(n, mid);
        if (total_reduction <= x)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

// int binarySearch(int mi, int mx, int x, int n)
// {
//     if (mi > mx)
//     {
//         return ans;
//     }

//     int mid = (mi + mx) / 2;
//     if (caluclate(a, n, mid) <= x)
//     {
//         ans1 = true;
//         ans = max(ans, mid);
//         return binarySearch(mid + 1, mx, x, n);
//     }
//     else{
//         if(ans1){
//             return ans;
//         }
//         return binarySearch(mi, mid - 1, x, n);
//     }

// }

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        ans = -1;
        ans1 = false;
        int mx = 0, mi = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        mx = a[n - 1];
        mi = a[0];
        mx += ((x + n - 1) / n);
        mi += (x / n);

        cout << binarySearch(n, x) << endl;
    }
}
