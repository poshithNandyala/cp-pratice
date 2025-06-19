#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        // dp[i] = minimum deletions needed to make suffix starting at position i beautiful
        vector<int> dp(n + 1);

        // Base case: dp[n] = 0 (empty sequence is beautiful)
        dp[n] = 0;

        // Fill dp array from right to left (bottom-up approach)
        for (int i = n - 1; i >= 0; i--)
        {
            // Option 1: Delete current element v[i]
            // Cost = 1 (delete v[i]) + dp[i+1] (make rest beautiful)
            dp[i] = dp[i + 1] + 1;

            // Option 2: Use v[i] as the start of a block
            // v[i] becomes the block length, so we need v[i] more elements
            // Block would be: v[i], v[i+1], v[i+2], ..., v[i+v[i]]
            // This requires positions i+1 through i+v[i] (total v[i] elements)
            // After this block, we continue from position i+v[i]+1

            if (i + v[i] + 1 <= n)
            { // Check if we have enough elements for the block
                // Cost = 0 (keep current block) + dp[i+v[i]+1] (make rest beautiful)
                dp[i] = min(dp[i], dp[i + v[i] + 1]);
            }

            /*
            Example walkthrough for [3, 3, 4, 5, 2, 6, 1]:
            Position 0: v[0] = 3
            - Option 1: Delete 3, cost = 1 + dp[1]
            - Option 2: Use 3 as block length, block = [3, 3, 4, 5], continue from position 4
                       cost = 0 + dp[4]

            Position 4: v[4] = 2
            - Option 1: Delete 2, cost = 1 + dp[5]
            - Option 2: Use 2 as block length, block = [2, 6, 1], continue from position 7
                       cost = 0 + dp[7] = 0 + 0 = 0
            */
        }

        // Answer is minimum deletions needed to make entire sequence beautiful
        cout << dp[0] << '\n';
    }

    return 0;
}

/*
Key Insights:
1. We use dynamic programming working backwards from the end
2. At each position, we have two choices:
   - Delete the current element (cost = 1 + solve rest)
   - Use current element as block start (cost = 0 + solve after block)
3. For option 2, we need exactly v[i] elements after position i to form a valid block
4. The recurrence is: dp[i] = min(1 + dp[i+1], dp[i+v[i]+1]) if valid block possible

Time Complexity: O(n) per test case
Space Complexity: O(n) for the dp array
*/