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
        int a[6];
        int ans = 1;
        for (int i = 1; i <= 5; i++)
        {
            if (i == 3)
            {
                a[i] = a[1] + a[2];
            }
            else
            {
                cin >> a[i];
            }
        }
        int temp = 0;
        for (int i = 1; i <= 3;i++){
            if(a[i+2]==a[i+1] + a[i]){
                temp++;
            }
        }
        ans=max(temp,ans);
        a[3]=a[5]-a[4];
        temp=0;
        for (int i = 1; i <= 3;i++){
            if(a[i+2]==a[i+1] + a[i]){
                temp++;
            }
        }   
        ans=max(temp,ans);
        cout<<ans<<endl;
    }
}