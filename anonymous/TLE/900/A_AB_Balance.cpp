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
        string s;
        cin >> s;
        int n = s.size();
        string ans;
        if (s[0] != s[n - 1])
        {
            s[n - 1] = s[0];
        }
        else
        {
        //     int cnt1 = 1, cnt2 = 1;
        //     string s1=s, s2=s;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (s[i] == s[i + 1])
        //         {
        //             cnt1++;
        //             if(s[i]=='a'){
        //                 s1[i] = 'b';
        //             }
        //             else{
        //                 s1[i] = 'a';
        //             }
        //         }
        //         else
        //         {
        //             if (s[i] == 'a')
        //             {
        //                 s1[i] = 'b';
        //             }
        //             else
        //             {
        //                 s1[i] = 'a';
        //             }
        //             break;
        //         }              
        //     }
        //     for (int i = n - 1; i >= 0; i--)
        //     {
        //         if (s[i] == s[i - 1])
        //         {
        //             cnt2++;
        //             if(s[i]=='a'){
        //                 s2[i] = 'b';
        //             }
        //             else{
        //                 s2[i] = 'a';
        //             }
        //         }
        //         else
        //         {
        //             if (s[i] == 'a')
        //             {
        //                 s2[i] = 'b';
        //             }
        //             else
        //             {
        //                 s2[i] = 'a';
        //             }
        //             break;
        //         }
        //     }
        //     if (cnt1 >=  cnt2)
        //     {
        //         ans = s2;
        //     }
        //     else
        //     {
        //         ans = s1;
        //     }
        
        }
        cout << s << endl;
    }
}