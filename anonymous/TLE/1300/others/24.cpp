// B. Just Eat It! - Codeforces problem solution
#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int T, n, i, flag;
    // Read number of test cases
    for (cin >> T; T > 0; T--)
    {
        // Read array size
        cin >> n;
        // Initialize prefix sum array
        a[0] = 0;
        // Calculate prefix sums
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        // Check if Yasser will be happy
        flag = 0;
        // Check all possible segments except [1,n]
        for (i = 1; i < n; i++)
        {
            // If any segment sum from start or to end is >= total sum
            // then Adel can choose that segment and Yasser won't be happy
            if (a[i] <= a[0] || a[i] >= a[n])
                flag = 1;
        }
        // Output result
        if (flag)
            cout << "NO\n"; // Yasser won't be happy
        else
            cout << "YES\n"; // Yasser will be happy
    }
    return 0;
}