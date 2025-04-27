#include <bits/stdc++.h>
using namespace std;
#define int long long int // Make int into long long int for larger values

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read number of test cases

    while (t--)
    {
        int n, m;
        cin >> n >> m; // Read number of friends and number of bad pairs

        vector<int> res(n + 1, 0); // res[i] stores max(min(a,b)) for bad pairs involving i

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            // For every non-friend pair, update res[max(a,b)] to track conflict
            res[max(a, b)] = max(res[max(a, b)], min(a, b));
        }

        int ans = 0; // Final answer
        int len = 1; // Current length of good segment

        for (int i = 1; i <= n; i++)
        {
            int newlen = i - res[i]; // Calculate possible segment length ending at i
            len = min(len, newlen);  // Choose the minimum to stay within good bounds
            ans += len;              // Add possible good subsegments ending at i
            len++;                   // Increase len for next iteration
        }

        cout << ans << endl; // Output the answer for this test case
    }
}
