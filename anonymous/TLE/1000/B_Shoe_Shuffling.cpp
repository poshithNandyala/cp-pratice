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
        int a[n];
        map<int, vector<int>> mpv;
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mpv[a[i]].push_back(i+1);
        }
        for (auto i : mpv)
        {
            if (i.second.size() == 1)
            {
                ans = false;
                break;
            }
        }
        map<int, bool> mp;
        map<int, int> id;
        if (ans)
        {
            for (int i = 0; i < n; i++)
            {
                if (!mp[a[i]])
                {
                    cout << mpv[a[i]][mpv[a[i]].size() - 1] << " ";
                    mp[a[i]] = true;
                }
                else
                {
                    cout << mpv[a[i]][id[a[i]]++] << " ";
                }
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}