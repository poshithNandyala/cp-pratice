#include <bits/stdc++.h> // Includes all standard headers
using namespace std;

#define ll long long // Shortcut for long long
#define endl '\n'    // Redefines endl for faster newline printing
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); // Speeds up cin/cout by decoupling from C stdio

int main()
{
    fastio // Apply fast IO settings

        ll n,
        m; // n = number of rows, m = number of columns
    cin >> n >> m;

    // mp counts frequency of each color (not used in logic, can be omitted)
    map<ll, ll> mp;

    // mprv: maps color -> list of rows where this color appears
    map<ll, vector<ll>> mprv;

    // mpcv: maps color -> list of columns where this color appears
    map<ll, vector<ll>> mpcv;

    // 2D array a to store the matrix (1-based indexing)
    ll a[n + 1][m + 1];

    // Reading matrix input
    for (int i = 1; i <= n; i++) // Loop over rows
    {
        for (int j = 1; j <= m; j++) // Loop over columns
        {
            cin >> a[i][j]; // Input color of cell at (i, j)

            mp[a[i][j]]++; // Count frequency of the color (not needed in actual logic)

            mprv[a[i][j]].push_back(i); // Store the row index for this color
            mpcv[a[i][j]].push_back(j); // Store the column index for this color
        }
    }

    ll ans = 0; // Final answer: total sum of Manhattan distances between same-colored pairs

    // Loop over all colors and process row-based distances
    for (auto it : mprv)
    {
        // Only proceed if the color appears in more than one row (more than one occurrence)
        if (it.second.size() > 1)
        {
            // Sort the row indices
            sort(it.second.begin(), it.second.end());

            ll sum = 0; // Cumulative sum of row indices so far

            // Calculate sum of distances using prefix sum trick:
            // For each i, contribution is: (i * current_value - sum_of_all_previous_values)
            for (int i = 0; i < it.second.size(); i++)
            {
                ans += i * it.second[i] - sum; // Adds distances to previous same-colored cells
                sum += it.second[i];           // Update cumulative sum
            }
        }
    }

    // Now do the same for columns
    for (auto it : mpcv)
    {
        if (it.second.size() > 1)
        {
            sort(it.second.begin(), it.second.end());

            ll sum = 0;
            for (int i = 0; i < it.second.size(); i++)
            {
                ans += i * it.second[i] - sum; // Same logic as row-wise
                sum += it.second[i];
            }
        }
    }

    // Output the final answer
    cout << ans << endl;
}
