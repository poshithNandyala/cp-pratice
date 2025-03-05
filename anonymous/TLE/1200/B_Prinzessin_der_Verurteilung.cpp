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
        string str = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < 26; i++)
        {
            if (s.find(str[i]) == string::npos)
            {
                cout << str[i] << endl;
                goto next_case;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                string str = string(1, 'a' + i) + string(1, 'a' + j);
                if (s.find(str) == string::npos)
                {
                    cout << str << endl;
                    goto next_case;
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    string str = string(1, 'a' + i) + string(1, 'a' + j) + string(1, 'a' + k);
                    if (s.find(str) == string::npos)
                    {
                        cout << str << endl;
                        goto next_case;
                    }
                }
            }
        }
    next_case:;
    }
}