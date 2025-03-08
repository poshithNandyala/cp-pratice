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
        string a, b;
        cin >> a >> b;
        vector<int> v;
        v.push_back(-1);
        int zero = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
            if (zero == one)
            {
                v.push_back(i);
            }
        }
        // for (auto item : v)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";

        vector<bool> v1;
        for (int i = 1; i < v.size(); i++)
        {
            if (a[v[i]] != b[v[i]])
            {
                v1.push_back(false);
            }
            else
            {
                v1.push_back(true);
            }
        }

        bool ans = true;

        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = v[i] + 1; j <= v[i + 1]; j++)
            {
                if (v1[i] == false)
                {
                    if (a[j] == '0')
                    {
                        a[j] = '1';
                    }
                    else
                    {
                        a[j] = '0';
                    }
                }
            }
        }
        // cout<<"a = "<<a<<endl;
        // cout<<"b = "<<b<<endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}