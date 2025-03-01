#include <bits/stdc++.h>
using namespace std;
void ts() { cout << "IAKIOI" << endl; }
int T, n;
string s;
char c;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> c >> s;
        s = ' ' + s;
        int ff = 1;
        for (int i = 1; i <= n; i++)
            ff &= (s[i] == c);
        if (ff)
        {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            int F = 1;
            for (int j = i; j <= n; j += i)
                F &= (s[j] == c);
            if (F)
            {
                cout << "1\n"
                     << i << '\n';
                goto end;
            }
        }
        cout << "2\n"
             << n << ' ' << n - 1 << '\n';
    end:;
    }
    return 0;
}
