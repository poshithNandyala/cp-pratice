#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int k;
        cin >> k;
        int low = k, high = k, changes = 0;
        for (int i = 1; i < n; i++)
        {
            cin >> k;
            low = min(k, low);
            high = max(k, high);
            if (high - low > 2 * x)
            {
                changes++;
                low = k;
                high = k;
            }
        }
        cout << changes << '\n';
    }
    return 0;
}