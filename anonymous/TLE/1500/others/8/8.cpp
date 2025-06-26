#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, pos = 0;
        long long ans = 0, x;
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;

            // 1) Always pay to conquer the next kingdom from wherever your capital is:
            //    cost = b * |x - pos|
            ans += b * llabs(x - pos);

            // 2) Then decide: “Should I move my capital forward to x before
            //    tackling the remaining kingdoms?”
            //
            //    If I DON’T move it, every remaining kingdom (there are
            //    (n − i) of them after this one) will again cost me b * (distance)
            //    to cross this same gap in the future.
            //
            //    If I DO move it, I pay once: a * (distance).
            //
            //    So it’s worth moving exactly when
            //
            //       cost_of_waiting = (n − i) * b * |x − pos|
            //       cost_of_moving  =       a * |x − pos|
            //
            //    Move when  (n − i) * b  >  a.
            //
            if (1ll * (n - i) * b > a)
            {
                // Move the capital to x:
                ans += 1ll * a * llabs(x - pos);
                pos = x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
