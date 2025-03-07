#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n;
    string s;
    while (t--)
    {
        cin >> n >> s;
        int c = count(s.begin(), s.end(), '0');
        if (n % 2 && s[n / 2] == '0' && c > 1)
            cout << "ALICE\n";
        else
            cout << "BOB\n";
    }
}