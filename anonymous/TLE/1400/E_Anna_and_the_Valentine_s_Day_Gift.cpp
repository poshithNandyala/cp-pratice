#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
int cz(int n)
{
    int cnt = 0;
    while (n % 10 == 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}
int cnt(int n){
    string s = to_string(n);
    return s.length();
}
int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum+= cnt(a[i]);
            a[i] = cz(a[i]);
        }
        // for(auto item : a){
        //     cout << item << " ";
        // }
        // cout << "\n";
        
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < n; i += 2)
        {
            sum -= a[i];
        }
        // cout<<sum<<endl;
        if(sum>m){
            cout << "Sasha" << endl;
        }
        else{
            cout << "Anna" << endl;
        }
    }
}