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
        string s;
        cin >> n >> s;
        int ans = 0,c=1;
        for(int i = 0; i < n; i++){
            if(s[i]==s[i+1]){
                c++;
            }
            else{
                ans = max(ans,c+1);
                c = 1;
            }
        }
        ans = max(ans, c + 1);
        cout << ans << endl;
    }
}