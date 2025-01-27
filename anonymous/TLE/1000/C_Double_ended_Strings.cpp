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
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                {
                    int c = 0;
                    int k = i, l = j;
                    while (k < n && l < m && a[k] == b[l])
                    {
                        c++;
                        k++;
                        l++;
                    }
                    ans = max(ans, c);
                }
            }
        }
        cout << n + m - (2 * ans) << endl;
    }
}