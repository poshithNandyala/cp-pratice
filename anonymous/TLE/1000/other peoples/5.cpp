#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x = x % k;
            if (x == 0)
            {
                x = k;
            }
            p[i].first = -x;
            p[i].second = i + 1;
        }
        sort(p, p + n);
        for (int i = 0; i < n; i++)
        {
            cout << p[i].second << " ";
        }
        cout << endl;
    }
}