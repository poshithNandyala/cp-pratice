#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "\n";
    cout << "First Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Second Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Third Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Fourth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Fifth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Sixth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Seventh Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (2 * (i - 1)) + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Eighth Pattern: \n";
    for (int i = n; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (2 * (i - 1)) + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Ninth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (2 * (i - 1)) + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (2 * (i - 1)) + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Tenth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Eleventh Pattern: \n";
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        flag = (i % 2);
        for (int j = 1; j <= i; j++)
        {
            cout << flag << " ";
            flag = !flag;
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Twelfth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = i + 1; j <= (2 * n) - i; j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Thirteenth Pattern: \n";
    int v = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            v++;
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Fourteenth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Fifteenth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Sixteenth Pattern: \n";
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ch;
        }
        cout << endl;
        ch++;
    }
    cout << "\n";
    cout << "Seventeenth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        char ch = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << ch;
            ch++;
        }
        ch--;
        for (int j = 1; j < i; j++)
        {
            ch--;
            cout << ch;
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Eighteenth Pattern: \n";
    ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        ch++;
    }
    for (int i = 1; i <= n; i++)
    {
        ch--;
        char c = ch;
        for (int j = 1; j <= i; j++)
        {
            cout << c << ' ';
            c++;
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Nineteenth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= (2 * (i - 1)); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= (2 * (n - i)); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Twentieth Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*" << " ";
        }
        for (int j = 1; j <= (2 * (n - i)); j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << "*" << " ";
        }
        for (int j = 1; j <= (2 * (i - 1)); j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Twenty First Pattern: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1 || j == n || i == 1 || i == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Twenty Second Pattern: \n";
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int ans = 100000000;
            ans = min(ans, i);
            ans = min(ans, j);
            ans = min(ans, 2 * n - 1 - i - 1);
            ans = min(ans, 2 * n - 1 - j - 1);
            cout << n - ans << " ";
        }
        cout << endl;
    }
}
