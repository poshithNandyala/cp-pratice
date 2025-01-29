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
        int cnt = 0, open = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                open++;
            }

            else
            {
                if (open > 0)
                {
                    open--;
                }
                else
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}