// This code solves the Orac and Models problem from Codeforces
// Problem: Given n models with sizes, find max length of sequence where:
// 1. Models must be arranged in increasing index order
// 2. For adjacent models i,j: j must be divisible by i
// 3. Size of model i must be less than size of model j

#include <bits/stdc++.h>
using namespace std;

#define ll long long  // Define long long as ll for shorter code
#define endl '\n'     // Define endl as newline character for faster output
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 // Fast I/O settings

int n;                  // Number of models
vector<int> a;         // Array to store sizes of models 
vector<int> dp;        // dp[i] stores max length possible starting from index i

// Recursive function to find longest valid sequence starting at index i
int func(int i)
{
    if (i == n)        // Base case: reached end of array
        return 0;
    
    int ans = 0;       // Store maximum length found
    // Try all multiples of current index as next element
    for (int j = 2 * i; j <= n; j += i)
    {
        if (a[j] > a[i])   // Check if size condition satisfied
        {
            if (dp[j] == -1)    // If not already computed
            {
                dp[j] = func(j); // Compute recursively
            }
            ans = max(ans, 1 + dp[j]); // Update max length
        }
    }
    return ans;
}

int main()
{
    fastio 
    int t;           // Number of test cases
    cin >> t;
    while (t--)
    {
        cin >> n;
        // Initialize arrays with size n+1 (1-based indexing)
        a = vector<int>(n + 1);
        dp = vector<int>(n + 1, -1);
        dp[0] = 0;    // Base case
        a[0] = 0;     // Dummy value at index 0
        
        // Input model sizes
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        
        int mx = 1;   // Minimum answer is 1 (single model)
        // Try each index as starting point
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == -1)
            {
                dp[i] = func(i);  // Compute if not already done
            }
            mx = max(mx, 1 + dp[i]); // Update maximum length
        }
        cout << mx << endl;  // Output answer for current test case
    }
}