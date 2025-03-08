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
        vector<int> a(n);
        map<int, int> mp;
        int ii = 1, jj = 0, ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            if ((mp.size() == 2) && ans2 == 0)
            {
                ans2 = a[i];
                jj = i + 1;
            }
        }
        ans1 = a[0];
        if (mp.size() == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                if ((i + 1 == ii) || (i + 1 == jj))
                {
                    continue;
                }
                else if (a[i] != ans1)
                {
                    cout << i + 1 << " " << ii << endl;
                }
                else{
                    cout << i + 1 << " " << jj << endl;
                }
            }
            cout <<ii << " " << jj << endl;
        }
    }
}