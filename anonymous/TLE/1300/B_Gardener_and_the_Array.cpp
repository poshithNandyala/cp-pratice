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
        vector<vector<int>> a;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            int x;
            cin >> x;
            for (int i = 0; i < x; i++)
            {
                int y;
                cin >> y;
                mp[y]++;
                temp.push_back(y);
            }
            a.push_back(temp);
        }
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            bool ans1 = true;
            for (int j = 0; j < a[i].size(); j++)
            {
                if (mp[a[i][j]] == 1)
                {
                    ans1 = false;
                    break;
                }
            }
            if (ans1){
                ans = true;
                break;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}