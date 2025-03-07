#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int k = count(s.begin(), s.end(), '0');
        if (k == 1 or k % 2 == 0)
        {
            cout << "BOB" << "\n";
        }
        else
        {
            cout << "ALICE" << "\n";
        }
    }

    return 0;
}
