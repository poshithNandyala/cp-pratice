#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int count[] = {0, 0};
    for (char &x : s)
        count[x - '0']++;

    for (int i = 0; i < s.size(); i++)
    {
        if (count[1 - (s[i] - '0')] == 0)
        {
            cout << s.size() - i << endl;
            return;
        }
        count[1 - (s[i] - '0')]--;
    }
    cout << 0 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}