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
        cout << 1 << " " << 1 << " ";
        for (int i = 2; i < n - 2; i++)
        {
            cout << i << " ";
        }
        cout << 1 << " " << 2 << endl;
    }
}