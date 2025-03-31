#include <bits/stdc++.h> // Includes all standard libraries in C++
using namespace std;

int main()
{
    int t;
    cin >> t; // Read the number of test cases

    while (t--)
    { // Iterate through each test case
        int n;
        cin >> n; // Read the number of nodes in the tree

        vector<int> a(n); // Store parent-child relationships
        for (int i = 1; i < n; ++i)
            cin >> a[i], a[i]--;
        // Read parent-child relationships for nodes 2 to n
        // We subtract 1 to convert to 0-based indexing

        string s;
        cin >> s; // Read the color string for the nodes

        vector<int> b(n); // This will store the balance factor of each node
        for (int i = 0; i < n; ++i)
            b[i] = (s[i] == 'W' ? 1 : -1);
        // Convert 'W' to +1 and 'B' to -1 for easy computation

        for (int i = n - 1; i >= 1; --i)
            b[a[i]] += b[i];
        // Propagate balance values upwards in the tree
        // If a node has a value, it contributes to its parent's value

        int ans = 0; // Counter for balanced subtrees
        for (int i = 0; i < n; ++i)
            ans += (b[i] == 0);
        // If the net balance of a subtree (rooted at i) is zero, it's balanced

        cout << ans << "\n"; // Output the result for this test case
    }
}
