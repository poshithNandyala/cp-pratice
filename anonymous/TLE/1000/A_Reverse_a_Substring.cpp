#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0;
    bool ans = false;
    int ma = s[0] - 'a';
    for (int i = 1; i < n; i++)
    {
        if (ma < (s[i] - 'a'))
        {
            l = i;
            ma = s[i] - 'a';
        }
        else if (ma > (s[i] - 'a'))
        {

            r = i;
            ans = true;
            break;
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
        cout << l + 1 << " " << r + 1 << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
