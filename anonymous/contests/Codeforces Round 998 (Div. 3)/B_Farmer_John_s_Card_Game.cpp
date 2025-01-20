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
        int n, m;
        cin >> n >> m;

        vector<int> v((n * m));
        vector<int> ve(n, -1);

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                v[x] = i;
                if (x < n)
                {
                    ve[x] = i;
                }
            }
        }
        // for(auto item : ve){
        //     cout << item << " ";
        // }
        // cout << "\n";
        // for(auto item : v){
        //     cout << item << " ";
        // }
        // cout << "\n";
        
        bool ans = true;
        for (int i = 0; i < n*m; i+=n)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i + j] != ve[j])
                {
                    // cout<<"i"<<i<<" j"<<j<<endl;
                    ans = false;
                    break;
                }
            }
            if (!ans)
            {
                break;
            }
        }
        if (ans)
        {
            for (auto item : ve)
            {
                cout << item +1<< " ";
            }
            cout << "\n";
        }
        else
        {
            cout << -1 << endl;
        }
    }
}