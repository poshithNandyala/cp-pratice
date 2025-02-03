#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long l = 1, r = 2E9;
    while (l <= r)
    {
        long long h = (l + r) >> 1, s = 0;
        for (int i = 0; i < n; i++)
            if (a[i] < h)
                s += h - a[i];
        if (s <= x)
            l = h + 1;
        else
            r = h - 1;
    }
    cout << r << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        fun();
    return 0;
}