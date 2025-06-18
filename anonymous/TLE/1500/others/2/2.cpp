#include <bits/stdc++.h> // Includes all standard C++ libraries like vector, algorithm, iostream, etc.
using namespace std;

int main()
{
    int t;
    cin >> t; // Read number of test cases

    while (t--)
    { // Loop through each test case
        long long n;
        cin >> n; // Read number of hordes (groups of monsters)

        long long a[n];    // Array to store number of monsters in each horde
        long long sum = 0; // Total number of monsters across all hordes

        // Read the number of monsters in each horde and calculate total sum
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; // Read monsters in horde i
            sum += a[i]; // Add to total monster count
        }

        // Sort the array in increasing order so we can process smaller hordes first
        sort(a, a + n);

        long long k = 0; // This will store the cumulative sum of monsters from the beginning
        int j = 0;       // This counts how many hordes we can include before exceeding half of total monsters

        // Try adding monsters from the smallest hordes until we go beyond half the total
        for (int i = 0; i < n; i++)
        {
            k += a[i]; // Add monsters from the i-th horde to our cumulative count

            // Once our cumulative count exceeds half the total, we stop
            if (k > (sum + 1) / 2)
            {
                break;
            }

            j++; // Count this horde as "included in the smaller half"
        }

        // -----------------------
        // Let's break down the formula below:
        //
        // (sum + 1) / 2:
        //   - This is the minimum number of Type 1 attacks (each kills 1 monster and increases combo counter)
        //   - We round up using (sum + 1)/2 to make sure we always get the ceiling (e.g., 5/2 = 2.5 → 3)

        // n - j:
        //   - After using Type 1 attacks on `j` small hordes, we are left with (n - j) bigger hordes
        //   - For each of these remaining hordes, we will use 1 Type 2 attack
        //     (each Type 2 attack kills `x` monsters and resets x to 0)
        //
        // So, total minimum attacks = ceil(sum / 2) + number of large hordes that need Type 2 attacks
        // -----------------------

        cout << ((sum + 1) / 2) + n - j << endl; // Output the answer for the current test case
    }
}
