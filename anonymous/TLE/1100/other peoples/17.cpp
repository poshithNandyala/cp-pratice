#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                diff += (a[i][j] != a[n - i - 1][n - j - 1]);
        }
        diff /= 2;
        if (diff > k)
        {
            cout << "NO\n";
            continue;
        }
        if (n & 1)
            cout << "YES\n";
        else if ((k - diff) & 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}