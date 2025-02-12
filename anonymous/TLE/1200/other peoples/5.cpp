#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int T, n, k, l[N];
priority_queue<int> d[N];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        int ans = n;
        for (int i = 1, x; i <= n; i++)
            cin >> x, d[x].push(i - l[x] - 1), l[x] = i;
        for (int j = 1; j <= k; j++)
            d[j].push(n - l[j]), l[j] = 0;
        for (int j = 1; j <= k; j++)
        {
            int x = d[j].top();
            d[j].pop();
            d[j].push(x / 2);
            ans = min(ans, d[j].top());
            while (!d[j].empty())
                d[j].pop();
        }
        cout << ans << '\n';
    }
    return 0;
}