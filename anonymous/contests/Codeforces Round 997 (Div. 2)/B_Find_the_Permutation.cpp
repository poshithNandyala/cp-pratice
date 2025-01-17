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
        string s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        vector<int> p1,p2;
        for (int i = 1; i <= n; i++)
        {
            p1.push_back(n-i+1);
            p2.push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i][j] == '1')
                {
                    swap(p1[i], p1[j]);
                }
                else{
                    swap(p2[i], p2[j]);
                }
            }
        }
        for(auto item : p1){
            cout << item << " ";
        }
        cout << "\n";
        for(auto item : p2){
            cout << item << " ";
        }
        cout << "\n";
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (s[i][j] == '1' && p1[i] > p1[j])
                {
                    swap(p1[i], p1[j]);

                }
                if (s[i][j] == '1' && p2[p2[i]] > p2[p2[j]])
                {
                    cout<<"i"<<i<<"j"<<j<<endl;
                    cout<<"p2[i] = "<<p2[i]<<" p2[j] = "<<p2[j]<<"one"<<endl;
                    swap(p2[i], p2[j]);
                    swap(p2[p2[i]], p2[p2[j]]); // swap(p1[i], p2[j]);
                }
                // if(s[i][j] == '0' && p1[i] < p1[j])
                // {
                //     swap(p1[i], p1[j]);
                // }
                // if(s[i][j] == '0' && p2[i] < p2[j])
                // {
                //     cout<<"p2[i] = "<<p2[i]<<" p2[j] = "<<p2[j]<<"zero"<<endl;
                //     swap(p2[i], p2[j]);
                // }
            }
        }
        for(auto item : p1){
            cout << item << " ";
        }
        cout << "\n";
        
        for (int i = 0; i < n; i++)
        {
            cout << p2[i] << " ";
        }
        cout << "\n";
    }
}