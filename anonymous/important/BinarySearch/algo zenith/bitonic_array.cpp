#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int n;
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

        cin >> n;
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
        cout << arr[ans] << endl;
        arr.clear();
    }
}