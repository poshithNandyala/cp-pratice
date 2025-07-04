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
        vector<pair<int, int>> v(n);
        vector<int> xx, yy;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
            xx.push_back(x);
            yy.push_back(y);
        }
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            s.insert({xx[i], yy[i]});
        }
       
    }
}