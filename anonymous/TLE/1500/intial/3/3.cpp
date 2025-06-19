#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int mi = INT_MAX;
void rec(int i, int c, int ans, int n, vector<int> &a)
{
    if (i == -1)
    {
        mi = min(mi, ans + c);
        return;
    }

    if (a[i] == c)
    {
        rec(i - 1, 0, ans, n, a);
    }
    if (a[i] < c)
    {
        rec(i - 1, 0, ans + c - a[i], n, a);
    }
    rec(i - 1, c + 1, ans, n, a);
}
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
        rec(n - 1, 0, 0, n, a);
        cout << mi << endl;
        mi = INT_MAX;
    }
}