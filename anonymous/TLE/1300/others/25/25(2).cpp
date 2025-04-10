#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N], b[N], c[N];

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    int minn = 1e9;
    int sum = 0;
    for (int i = n; i >= 1; i--)
    {
        if (c[b[i]] > minn)
            sum++;
        minn = min(minn, c[b[i]]);
    }
    cout << sum;

    return 0;
}
