#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int n, q, k;
vector<int> arr;
bool check(int mid)
{
    return (mid == n - 1) || (arr[mid] > arr[mid + 1]);
}
int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> q;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
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
        int ans1 = -1;
        int ans2 = -1;
        while (q--)
        {
            int k;
            cin >> k;
            low = 0, high = ans;
            ans1=-1;
            ans2=-1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[mid] == k)
                {
                    ans1 = mid;
                    break;
                }
                else if (arr[mid] > k)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            low = ans + 1;
            high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[mid] == k)
                {
                    ans2 = mid;
                    break;
                }
                else if (arr[mid] > k)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if (ans1 != -1)
            {
                cout << ans1 + 1 << " ";
            }
            if (ans2 != -1)
            {
                cout << ans2 + 1;
            }
            cout << endl;
        }
        arr.clear();
    }
}