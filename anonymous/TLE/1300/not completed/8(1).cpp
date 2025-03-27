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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++)
        {
            int lo = 0, hi = i;
            while (lo < hi)
            {
                int mid = (lo + hi + 1) / 2;
                int k = mid;
                bool possible = true;
                for (int j = i - mid + 1; j <= i; j++)
                {
                    if (a[j] < k)
                    {
                        possible = false;
                        break;
                    }
                    k--;
                }
                if (possible)
                {
                    lo = mid;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            int x = lo;
            cout << x << " ";
        }
        cout << endl;
    }
}