#include <bits/stdc++.h>
using namespace std;

#define int long long  // Use long long everywhere to avoid overflow
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    
    // MAXIMUM n we will handle
    const int nmax = 1e6; 
    
    // Step 1: Determine the size of a triangle (d)
    // We need d such that number of elements in a triangle = d*(d-1)/2 >= nmax
    // This is because we are going to fill numbers in a triangular pattern
    int d = 1;
    while (d * (d - 1) / 2 < nmax) d++; // find minimum d to cover all n

    // Step 2: Create a 2D array 'a' to hold prefix sums
    vector<vector<int>> a(d + 5, vector<int>(d + 5, 0));
    // 'ans[n]' will store the final answer for each n
    vector<int> ans(nmax + 1);

    int curr = 1; // current number we are filling (1 to nmax)

    // Step 3: Fill the triangular array
    // We iterate over diagonals of the triangle
    for (int i = 1; i <= d && curr <= nmax; i++) { // i = diagonal index
        for (int j = i - 1; j >= 1 && curr <= nmax; j--) { // j = row in diagonal
            int r = j, c = i - j; // convert diagonal index to 2D row/col

            // Step 3a: Fill the cell using inclusion-exclusion prefix sum formula
            // This formula ensures that a[r][c] = sum of squares from (1,1) to (r,c)
            // a[r][c] = sum of previous row + sum of previous column - overlap + curr^2
            a[r][c] = a[r - 1][c] + a[r][c - 1] - a[r - 1][c - 1] + curr * curr;

            // Step 3b: Store answer for this number
            ans[curr] = a[r][c];

            curr++; // move to next number
        }
    }

    // Step 4: Answer queries
    int t; // number of queries
    cin >> t;
    while (t--) {
        int n;
        cin >> n; // query number
        cout << ans[n] << endl; // output precomputed answer
    }
}
