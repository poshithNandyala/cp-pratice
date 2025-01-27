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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int first = 0, end = n - 1;
        bool ans = true;

        for (int j = 0; j < n; j++)
        {
            if ((a[j] <= (j - first) * 2) || (a[j] <= (end - j) * 2))
            {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }
}