#include <bits/stdc++.h>
using namespace std;

/*
 We have n kingdoms at positions x[1] < x[2] < … < x[n], starting from capital at 0.
 Two operations:
   1) Move capital from current c1 to any conquered kingdom c2 at cost a * |c1 - c2|.
   2) Conquer next unconquered kingdom at c2 from current capital c1 at cost b * |c1 - c2|.
 You cannot leapfrog unconquered kingdoms.

 KEY OBSERVATION (greedy):
   Consider the distance d_i = x[i] - x[i-1] for i=1…n (with x[0] = 0).
   At each segment of length d_i, there are (n - i + 1) kingdoms still to conquer beyond x[i-1].
   You have two ways to pay for “crossing” this segment:

   A) Don’t move the capital; conquer each of the remaining (n - i + 1)
      kingdoms by repeatedly paying b * d_i each time you cross this gap.
      Total cost = b * d_i * (n - i + 1).

   B) Move your capital from x[i-1] to x[i]:
      - First conquer x[i-1] (already done by definition, so capital is at x[i-1])
      - Move capital one step across the gap: cost = a * d_i
      - Conquer x[i] once (cost = b * d_i), and for all future kingdoms,
        this segment is “behind” the capital, so you only pay b * d_i once
        for the immediate conquest, not repeatedly.
      Total cost across this segment = (a + b) * d_i.

   Therefore, for each segment i you add:
     cost_i = min( b * d_i * (n - i + 1),
                   (a + b) * d_i ).

   Summing these minimal costs for i=1…n yields the global optimum.

 Time complexity is O(n) per test, which is fine for total n up to 2⋅10^5.

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b;

        vector<long long> x(n + 1);
        x[0] = 0; // treat the initial capital at position 0 as x[0]
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }

        long long answer = 0;
        // Process each gap between consecutive conquered positions
        for (int i = 1; i <= n; i++)
        {
            long long d = x[i] - x[i - 1];   // length of this segment
            long long remaining = n - i + 1; // number of kingdoms still beyond x[i-1]

            // Option A: never move capital across this gap
            //   we will cross it once for each remaining kingdom: cost = b * d * remaining
            long long costA = b * d * remaining;

            // Option B: move capital across this gap exactly once,
            //   then conquer the very next kingdom immediately:
            //   cost of move    = a * d
            //   cost of conquest = b * d
            //   total           = (a + b) * d
            long long costB = (a + b) * d;

            // Pick the cheaper of the two strategies for this segment
            answer += min(costA, costB);
        }

        cout << answer << "\n";
    }

    return 0;
}
