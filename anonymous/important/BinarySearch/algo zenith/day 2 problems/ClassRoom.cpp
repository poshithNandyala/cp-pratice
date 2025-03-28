#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

vector<int> a;
int n, k;

bool check(int mid)
{
    int seats = 1;
    int lastSeat = a[0];

    for (int i = 1; i < n; i++)
    {
        if ((a[i] - lastSeat) >= mid)
        {
            seats++;
            lastSeat = a[i]; 
        }
    }
    return seats >= k; 
}

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end()); // Sort seat positions

        int lo = 0, hi = a[n - 1] - a[0];
        int ans = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(mid))
            {
                ans = mid;   
                lo = mid + 1; 
            }
            else
            {
                hi = mid - 1; 
            }
        }

        cout << ans << endl;
    }
    return 0;
}
