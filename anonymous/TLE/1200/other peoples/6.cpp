#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int m = unique(a, a + n) - a;
        int res = 1;
        for (int i = 0; i + 1 < m; i++)
        {
            int j = i + 1;
            while (j + 1 < m && (a[j + 1] > a[j]) == (a[j] > a[j - 1]))
                j++;
            i = j - 1;
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}