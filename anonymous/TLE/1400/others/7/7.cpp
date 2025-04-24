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
        vector<int> ans(n);
        int sum = 0;
        int color = 0;
        int cnt = 1;
        int prev = (s[0] == '(') ? 1 : -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                sum++;
            else
                sum--;
            if ((prev > 0 && sum < 0) || (prev < 0 && sum > 0))
            {
                color ^= 1;
                prev = sum;
                cnt++;
            }
            ans[i] = color + 1;
        }
        if (sum == 0)
        {
            cout << min(cnt, 2) << endl;
            for (auto &it : ans)
                cout << it << " ";
        }
        else
            cout << -1 << " ";
        cout << endl;
    }
    // ((())) )(
    // 1 2 3 2 1 0  -1 0
    return 0;
}