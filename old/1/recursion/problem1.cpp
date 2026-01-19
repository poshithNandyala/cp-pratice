#include <bits/stdc++.h>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string ss = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (((s[i] >= 'A') && (s[i] <= 'z')))
            {
                ss.push_back(tolower(s[i]));
            }
            else if ((s[i]  <= '9') && (s[i]  >= '0'))
            {
                cout<<s[i]<<endl;
                ss.push_back(s[i]);
            }
        }
        cout << ss << endl;
        int n = ss.size();
        for (int i = 0; i < (n) / 2; i++)
        {
            if (ss[i] != ss[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string test;
    cin >> test;

    if (solution.isPalindrome(test))
    {
        cout << "\"" << test << "\" is a palindrome" << endl;
    }
    else
    {
        cout << "\"" << test << "\" is not a palindrome" << endl;
    }

    return 0;
}