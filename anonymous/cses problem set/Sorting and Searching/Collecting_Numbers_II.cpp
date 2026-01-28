#include <bits/stdc++.h>
using namespace std;

/*
========================================================
PROBLEM (Brief):
--------------------------------------------------------
You are given a permutation of numbers 1..n.
You want to collect numbers from 1 to n in increasing order.

You scan the array from left to right.
If the next number you want appears to the LEFT of the current one,
you must start a NEW round.

After each swap operation, output the number of rounds needed.
========================================================
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    /*
        a[i]   = value at index i (1-based indexing)
        pos[x] = current position (index) of value x
    */
    vector<int> a(n + 1), pos(n + 1);

    // Read the permutation and store positions
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    /*
        KEY IDEA:
        ---------
        Number of rounds depends on how many times
        position(i) > position(i+1).

        If i+1 appears BEFORE i in the array,
        we must start a new round.
    */

    int rounds = 1; // At least one round is always needed

    // Count initial "breakpoints"
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) {
            rounds++;
        }
    }

    // Process each swap query
    while (m--) {
        int i, j;
        cin >> i >> j;

        int u = a[i]; // value at position i
        int v = a[j]; // value at position j

        /*
            IMPORTANT OBSERVATION:
            ----------------------
            Swapping only affects the relative order of:
            (u-1, u), (u, u+1)
            (v-1, v), (v, v+1)

            All other pairs remain unchanged.
        */

        // Store unique affected pairs (x, x+1)
        set<int> affected;
        for (int x : {u - 1, u, v - 1, v}) {
            if (x >= 1 && x < n) {
                affected.insert(x);
            }
        }

        /*
            STEP 1:
            -------
            Remove OLD breakpoint contributions
            before performing the swap.
        */
        for (int x : affected) {
            if (pos[x] > pos[x + 1]) {
                rounds--;
            }
        }

        /*
            STEP 2:
            -------
            Perform the actual swap:
            - swap values in array
            - swap their positions
        */
        swap(a[i], a[j]);
        swap(pos[u], pos[v]);

        /*
            STEP 3:
            -------
            Add NEW breakpoint contributions
            after the swap.
        */
        for (int x : affected) {
            if (pos[x] > pos[x + 1]) {
                rounds++;
            }
        }

        // Output result after this swap
        cout << rounds << '\n';
    }

    return 0;
}
