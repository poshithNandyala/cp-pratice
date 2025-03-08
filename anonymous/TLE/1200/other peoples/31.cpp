#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        map<int, long long> mp;
        for (auto &it : v)
        {
            cin >> it;
            mp[__builtin_clz(it)]++;
        }
        long long cnt = 0;
        for (auto it : mp)
        {
            cnt += (it.second * (it.second - 1)) / 2;
        }
        cout << cnt << endl;
    }
}