#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int N;
double dp[301][301][301];
bool vis[301][301][301];

// ======================= IDEA =======================
//
// STEP 1: WHY (i, j, k)?
//   - We don't care WHICH dish has how many sushi.
//   - We only care HOW MANY dishes have 1, 2, or 3 sushi.
//   - Example: dishes = [2, 1, 3, 1] → i=2 (two 1's), j=1 (one 2), k=1 (one 3)
//   - This shrinks the state space from huge to at most O(N^3).
//
// STEP 2: WHAT HAPPENS IN ONE ROLL?
//   - Total dishes = N. Dishes with sushi = i + j + k. Empty dishes = N - i - j - k.
//   - We roll a die with N faces. Each dish is equally likely (prob = 1/N).
//
//   Case 1: We land on an EMPTY dish (there are N-i-j-k of them)
//     → Nothing happens. Wasted roll. State stays (i, j, k).
//     → Probability = (N - i - j - k) / N
//
//   Case 2: We land on a dish with 1 sushi (there are i of them)
//     → Eat 1. That dish goes from 1 → 0 (becomes empty). So i decreases by 1.
//     → New state: (i-1, j, k)
//     → Probability = i / N
//
//   Case 3: We land on a dish with 2 sushi (there are j of them)
//     → Eat 1. That dish goes from 2 → 1. So j decreases by 1, i increases by 1.
//     → New state: (i+1, j-1, k)
//     → Probability = j / N
//
//   Case 4: We land on a dish with 3 sushi (there are k of them)
//     → Eat 1. That dish goes from 3 → 2. So k decreases by 1, j increases by 1.
//     → New state: (i, j+1, k-1)
//     → Probability = k / N
//
// STEP 3: WRITE THE EQUATION
//   E(i,j,k) = 1 + ((N-i-j-k)/N) * E(i,j,k)       ← wasted (SAME state!)
//                + (i/N) * E(i-1, j, k)
//                + (j/N) * E(i+1, j-1, k)
//                + (k/N) * E(i, j+1, k-1)
//
// STEP 4: PROBLEM — E(i,j,k) appears on BOTH sides!
//   This is like the equation:  x = 1 + 0.5 * x
//   You can't just plug in recursively because it refers to itself.
//   Solution: solve it like algebra!
//
//   Move the self-term to the left side:
//     E - ((N-i-j-k)/N) * E = 1 + (i/N)*E₁ + (j/N)*E₂ + (k/N)*E₃
//
//   Factor out E on the left:
//     E * (1 - (N-i-j-k)/N) = 1 + (i/N)*E₁ + (j/N)*E₂ + (k/N)*E₃
//
//   Simplify:  1 - (N-i-j-k)/N  =  (N - N + i+j+k)/N  =  (i+j+k)/N
//     E * (i+j+k)/N = 1 + (i/N)*E₁ + (j/N)*E₂ + (k/N)*E₃
//
//   Multiply both sides by N:
//     E * (i+j+k) = N + i*E₁ + j*E₂ + k*E₃
//
//   Divide by (i+j+k):
//     E = (N + i*E(i-1,j,k) + j*E(i+1,j-1,k) + k*E(i,j+1,k-1)) / (i+j+k)
//
//   NOW there is NO self-reference! We can compute this recursively!
//
// STEP 5: WHY DOES RECURSION NOT LOOP FOREVER?
//   Total sushi = 1*i + 2*j + 3*k.
//   Every recursive call reduces total sushi by exactly 1:
//     (i-1, j, k)   → total = (i-1) + 2j + 3k       = total - 1  ✓
//     (i+1, j-1, k) → total = (i+1) + 2(j-1) + 3k   = total - 1  ✓
//     (i, j+1, k-1) → total = i + 2(j+1) + 3(k-1)   = total - 1  ✓
//   So we always move closer to (0,0,0) where E = 0. No infinite loop!
//
// ====================================================

double rec(int i, int j, int k) {
    // Base case: no sushi left, 0 rolls needed
    if (i == 0 && j == 0 && k == 0) return 0.0;

    // Check if we already computed this state (memoization / DP)
    if (vis[i][j][k]) return dp[i][j][k];
    vis[i][j][k] = true;

    // Apply the formula:
    // E = (N + i*E(i-1,j,k) + j*E(i+1,j-1,k) + k*E(i,j+1,k-1)) / (i+j+k)

    double res = N;                                // start with N (the "1 roll" after multiplying by N)
    if (i > 0) res += i * rec(i - 1, j, k);       // ate from a 1-sushi dish → dish becomes empty
    if (j > 0) res += j * rec(i + 1, j - 1, k);   // ate from a 2-sushi dish → dish drops to 1
    if (k > 0) res += k * rec(i, j + 1, k - 1);   // ate from a 3-sushi dish → dish drops to 2
    res /= (i + j + k);                            // divide by (i+j+k) to get final E

    // Store in dp and return
    return dp[i][j][k] = res;
}

int32_t main() {
    fastio
    int n;
    cin >> n;
    N = n;

    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) c1++;
        else if (a == 2) c2++;
        else c3++;
    }

    memset(vis, false, sizeof(vis));
    cout << fixed << setprecision(10) << rec(c1, c2, c3) << endl;
}
