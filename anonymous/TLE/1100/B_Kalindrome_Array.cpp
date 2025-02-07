#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

bool isPalindrome(vector<int> v){
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] != v[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int i = 0, j = n - 1;
        bool ans = true;
        int x, y;
        while (i <= j)
        {
            if (a[i] != a[j])
            {
                ans = false;
                x = a[i];
                y = a[j];
                break;
            }
            i++;
            j--;
        }
        if (!ans)
        {
            vector<int> v1, v2;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != x)
                {
                    v1.push_back(a[i]);
                }
                if (a[i] != y)
                {
                    v2.push_back(a[i]);
                }
                
            }
            // for(auto item : v1){
            //     cout << item << " ";
            // }
            // cout << "\n";
            // for(auto item : v2){
            //     cout << item << " ";
            // }
            // cout << "\n";
            
            if (isPalindrome(v1) || isPalindrome(v2))
            {
                ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}