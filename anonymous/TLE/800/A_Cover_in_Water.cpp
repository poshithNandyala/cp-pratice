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
        string s;
        cin >> s;
        vector<int> v;
        int c = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '.' && s[i + 1] == '.')
            {
                c++;
            }
            else if (s[i] == '.' && s[i + 1] == '#')
            {
                v.push_back(c);
                c = 1;
            }
        }
        int ma = 0;
        if (s[n - 1] == '.')
        {
            v.push_back(c);
          
        }
        int ans = 0;
        for (auto i : v)
        {
            ans += min(i, 2);
            ma = max(ma, i);
        }
        if(ma>=3){
            ans = 2;
        }
        cout << ans << endl;
    }
}