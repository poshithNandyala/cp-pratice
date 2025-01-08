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
        string s;
        cin >> s;
        int n = s.length();
        int ans;
        if ((s[n - 2] == '0' && s[n - 1] == '0') || (s[n - 2] == '5' && s[n - 1] == '0') || (s[n - 2] == '2' && s[n - 1] == '5') || (s[n - 2] == '7' && s[n - 1] == '5'))
        {
            ans = 0;
        }
        else
        {
            int ans1 = 0;
            for (int i = n - 1; i > 0; i--)
            {
                if ((s[i - 1] == '0' && s[i] == '0') || (s[i - 1] == '5' && s[i] == '0') || (s[i - 1] == '2' && s[i] == '5') || (s[i - 1] == '7' && s[i] == '5'))
                {
                    break;
                }
                ans1++;
            }
            // cout <<"ans1"<< ans1 << endl;
            int ans2 = INT_MAX;
            bool flag = true;
            int ind2;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '0' && flag)
                {
                    ind2 = i;
                    flag = false;
                }
                else if ((s[i] == '5' || s[i] == '0') && !flag)
                {
                    // cout << "ind2" << ind2 <<"i" << i<<"n"<<n << endl;
                    // cout << ind2 - i - 1 << endl;
                    // cout << n - 1 - i << endl;
                    // cout << "ans2" << ind2 - i - 1 + (n - 1 - ind2) << endl;
                    // ans2 = min(ans2, ind2 - i - 1 + (n - 1 - ind2));
                    ans2 = ind2 - i - 1 + (n - 1 - ind2);
                    // cout << "ans2" << ans2 << endl;
                    break;
                }
            }
            flag = true;
            for (int i = n - 1; i >=0; i--)
            {
                if (s[i] == '5' && flag)
                {
                    ind2 = i;
                    flag = false;
                }
                else if ((s[i] == '7' || s[i] == '2') && !flag)
                {
                    // cout << "ind2" << ind2 <<"i" << i<<"n"<<n << endl;
                    // cout << ind2 - i - 1 << endl;
                    // cout << n - 1 - i << endl;
                    // cout << "ans2" << ind2 - i - 1 + (n - 1 - ind2) << endl;
                    ans2 = min(ans2, ind2 - i - 1 + (n - 1 - ind2));
                    // cout << "ans2" << ans2 << endl;
                    break;
                }
            }
            ans = min(ans1, ans2);
        }
        cout << ans << endl;
    }
}