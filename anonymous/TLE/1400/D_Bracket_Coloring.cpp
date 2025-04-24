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
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                c1++;
            else
                c2++;
        }
        if (c1 == c2)
        {
            vector<int> ans(n);
            int cnt = 0, anss = 1, ans1 = 1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                {
                    cnt++;
                    ans[i] = 1;
                }
                else if (cnt)
                {
                    cnt--;
                    ans1 = 0;
                    ans[i] = 1;
                }
                else
                {
                    anss = 2;
                    ans[i] = 2;
                }
            }
            anss -= ans1;
            if (anss == 2 || cnt > 0)
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    if (s[i] == '(' && cnt > 0)
                    {
                        cnt--;
                        ans[i] = 2;
                    }
                }
            }
        
            if (anss == 1)
            {
                cout << anss << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << 1 << " ";
                }
            }
            else
            {
                int cnt = 0, anss = 1, ans1 = 1;
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == ')')
                    {
                        cnt++;
                        ans[i] = 1;
                    }
                    else if (cnt)
                    {
                        cnt--;
                        ans1 = 0;
                        ans[i] = 1;
                    }
                    else
                    {
                        anss = 2;
                        ans[i] = 2;
                    }
                }
                anss -= ans1;
                if (anss == 2 || cnt > 0)
                {
                    for (int i = n - 1; i >= 0; i--)
                    {
                        if (s[i] == ')' && cnt > 0)
                        {
                            cnt--;
                            ans[i] = 2;
                        }
                    }
                }
                cout << anss << endl;
                if (anss == 1)
                {
                    for (int i = 0; i < n; i++)
                    {
                        cout << 1 << " ";
                    }
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        cout << ans[i] << " ";
                    }
                }
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
