#include <bits/stdc++.h> // Includes all standard C++ standard library headers
using namespace std;

// Define convenient type alias for 64-bit integers
#define ll long long

// Redefine endl for faster flushing
#define endl '\n'

// Macro to enable fast IO: untie cin/cout and disable sync with stdio
#define fastio \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main() {
    fastio; // Apply fast IO settings

    int t;
    cin >> t;               // Read the number of test cases

    while (t--) {           // Loop over each test case
        ll n, m;
        cin >> n >> m;       // Read original price n, and max multiplier m
        
        // ans will hold the reduced price after stripping zeros
        ll ans = n;
        // z counts how many zeros we stripped off from the end of n
        ll z = 0;

        // Strip off and count all trailing zeros from ans
        // Each iteration removes one zero (divide by 10) and increments z
        while (ans > 0 && ans % 10 == 0) {
            ans /= 10;
            z++;
        }

        // k is the multiplier we're building to maximize trailing zeros
        ll k = 1;

        // If ans still has factor 5, pairing with factor 2 (via k *= 2) yields a 10
        // For each factor 5 in ans, try to multiply k by 2 to create an extra trailing zero
        while (ans > 0 && ans % 5 == 0) {
            ans /= 5;             // Remove one factor of 5 from ans
            if (k * 2 <= m) {     // Check if we can still multiply k by 2 without exceeding m
                k *= 2;           // Multiply k by 2 to pair with the removed 5 and form a 10
            } else {
                break;           // If k*2 would exceed m, stop trying further
            }
        }

        // Similarly, if ans has factor 2, pairing with factor 5 (via k *= 5) yields a 10
        while (ans > 0 && ans % 2 == 0) {
            ans /= 2;             // Remove one factor of 2 from ans
            if (k * 5 <= m) {     // Check if we can multiply k by 5 without exceeding m
                k *= 5;           // Multiply k by 5 to pair with removed 2 and form a 10
            } else {
                break;           // Stop if we'd exceed m
            }
        }

        // After handling existing factors, multiply by 10 directly as much as possible
        // Each multiplication by 10 adds one trailing zero
        while (k * 10 <= m) {
            k *= 10;
        }

        // ===== KEY STEP: maximize k under the bound m =====
        // Suppose k is now some value <= m that creates the most zeros so far.
        // But we can still scale k further by an integer factor without changing its
        // number of trailing zeros, as long as the result remains <= m.
        // (m / k) gives the largest integer factor we can multiply k by without
        // exceeding m; multiplying that factor by k yields the largest multiple of
        // k that is <= m. We then set k to that value.
        // Example: if m = 123 and k = 10, then m/k = 12, so (m/k)*k = 120.
        // This ensures we use the full budget up to m, maximizing n*k.
        k = (m / k) * k;

        // If original n had no zeros (z == 0) and we couldn't improve k (k == 1),
        // then no rounding improvement was possible. In that case output n*m directly.
        if (z == 0 && k == 1) {
            cout << (n * m) << endl;
        } else {
            // Otherwise, output n*k which is the largest "roundest" price
            cout << (n * k) << endl;
        }
    }

    return 0;
}
