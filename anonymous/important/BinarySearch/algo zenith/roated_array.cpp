#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int arr[1000000];
bool check(int mid)
{
    return arr[mid] < arr[0];
}
int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int low = 0, high = n - 1;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
}