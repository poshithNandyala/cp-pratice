#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int ans = 0;
        int i = 1;
        while ((n % i) == 0)
        {
            i++;
            ans++;
        }
        cout << ans << endl;
    }
}



// Let me explain in a simpler way with concrete examples.

// Let's take n = 40 and understand why we only need to check from the beginning:

// 1) Let's list ALL divisors of 40:
//    - Divisors of 40 are: 1, 2, 4, 5, 8, 10, 20, 40

// 2) Now, let's try to find consecutive numbers from this list:
//    - At beginning: 1, 2 (length = 2)
//    - In middle: 4, 5 (length = 2)
//    - Later: 8 (alone)
//    - Later: 10 (alone)
//    - Later: 20 (alone)
//    - End: 40 (alone)

// 3) Why can't we have consecutive numbers after 5?
//    - After 5, next divisor is 8
//    - But for numbers to be consecutive, 6 and 7 should also divide 40
//    - But 40 ÷ 6 = 6.666... (not divisible)
//    - 40 ÷ 7 = 5.714... (not divisible)
//    - So sequence breaks!

// 4) Why does this always happen?
//    - As numbers get bigger, gap between divisors gets bigger
//    - It's harder for bigger consecutive numbers to all be divisors
//    - For example, if 100 and 101 are both divisors:
//      - Number must be at least 100 × 101 = 10,100!
//    - This is why longest consecutive sequence is always at start

// Does this help explain it better? Let me know if you need more examples!