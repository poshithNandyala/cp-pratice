#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio int t=1;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2)
        {
            int v = (n / 2) + 2;
            cout << v * (v - 1) * 2 << endl;
        }
        else
        {
            int v = (n / 2) + 1;
            cout << v * v << endl;
        }
    }
}