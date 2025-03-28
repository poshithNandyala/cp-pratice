#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

bool isPossible(vector<ll> &boards, int n, int k, ll maxTime)
{
    int painters = 1;
    ll currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentSum + boards[i] <= maxTime)
        {
            currentSum += boards[i];
        }
        else
        {
            painters++;
            currentSum = boards[i];
            if (painters > k)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> boards(n);

        ll maxBoard = 0, totalLength = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> boards[i];
            maxBoard = max(maxBoard, boards[i]);
            totalLength += boards[i];
        }

        ll lo = maxBoard, hi = totalLength, ans = totalLength;

        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;

            if (isPossible(boards, n, k, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
