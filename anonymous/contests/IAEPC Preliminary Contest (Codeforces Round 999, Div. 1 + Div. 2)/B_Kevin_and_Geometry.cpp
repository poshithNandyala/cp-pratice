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
        int a[n];
        map<int, int> m, mx;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }

        bool ans = false;
        int eq, aa, bb, c;


        for (int i = 0; i < n; i++)
        {
            if (m[a[i]] >= 2)
            {
                mx[a[i]] = m[a[i]];
            }
        }

        sort(a, a + n);
        for (int i = 1; i < n; i++)
        {
            bb = a[i];
            aa = a[i - 1];
            int tempa = mx[aa], tempb = mx[bb];

     
            if (mx[aa] < 3)
            {
                mx.erase(aa);
            }
            else
            {
                mx[aa]--;
            }

            if (mx[bb] < 3)
            {
                mx.erase(bb);
            }
            else
            {
                mx[bb]--;
            }


            c = ((bb - aa) / 2);

            if (!mx.empty())
            {
                auto it = prev(mx.end());
                int first = it->first;
                int second = it->second;

                if ((first > c) && (second >= 2))
                {
                    eq = it->first;
                    ans = true;
                    break;
                }
            }

       
            if (tempa > 0)
            {
                mx[aa] = tempa;
            }
            if (tempb > 0)
            {
                mx[bb] = tempb;
            }
        }

        if (ans)
        {
            cout << eq << " " << eq << " " << aa << " " << bb << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
