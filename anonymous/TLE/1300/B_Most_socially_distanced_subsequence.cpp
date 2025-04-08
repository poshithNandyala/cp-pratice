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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> ans;
        ans.push_back(a[0]);
        int i = 1;
        while (i < n)
        {
            if (a[i] > ans.back())
            {
                while (i < n - 1 && a[i + 1] > a[i])
                {
                    i++;
                }
                ans.push_back(a[i]);
            }
            else if (a[i] < ans.back())
            {
                while (i < n - 1 && a[i + 1] < a[i])
                {
                    i++;
                }
                ans.push_back(a[i]);
            }
            i++;
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}