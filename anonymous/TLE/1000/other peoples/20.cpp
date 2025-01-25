#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, a, b, x;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if ((a - 1) % 4 == 0)
            x = a - 1;
        else if ((a - 1) % 4 == 1)
            x = 1;
        else if ((a - 1) % 4 == 2)
            x = a;
        else
            x = 0;
        if (x == b)
            cout << a;
        else if ((x ^ b) != a)
            cout << a + 1;
        else
            cout << a + 2;
        cout << '\n';
    }
    return 0;
}