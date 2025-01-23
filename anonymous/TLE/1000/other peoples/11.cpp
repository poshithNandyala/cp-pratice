#include <bits/stdc++.h>
using namespace std;
int n, d, a[100005];
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int cnt = 0, sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += d / a[i] + 1;
        if (sum > n)
            break;
        cnt++;
    }
    cout << cnt;
}