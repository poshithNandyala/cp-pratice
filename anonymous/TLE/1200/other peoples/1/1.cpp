#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    int ans = 0, ab = 0, ac = 0, bc = 0, A = 0, B = 0, C = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max({ans, a[i] + bc, b[i] + ac, c[i] + ab});
        ab = max({ab, a[i] + B, b[i] + A});
        ac = max({ac, a[i] + C, c[i] + A});
        bc = max({bc, b[i] + C, c[i] + B});
        A = max(A, a[i]);
        B = max(B, b[i]);
        C = max(C, c[i]);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}