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
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                cnt++;
            }
        }
        int ex = 0;
        if (cnt % 2)
        {
            ex = 1;
            cnt--;
        }
        cnt /= 2;
        if(ex==0 && cnt%2==0){
            cout<<"BOB"<<endl;
        }
        else if(ex && cnt%2==0){
            cout<<"ALICE"<<endl;
        }
        else if(ex && cnt%2==1){
            cout<<"ALICE"<<endl;
        }
        else if(ex==0 && cnt%2==1){
            cout<<"BOB"<<endl;
        }

    }
}