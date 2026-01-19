/*
             Timestamp  : 15:31 - Saturday  29,Mar 2025
*/
#include <bits/stdc++.h>
using namespace std;
int k = 0;
void subsequences(int i, vector<int> &a, vector<int> &ans)
{
    if (i == a.size())
    {
        k++;
        cout << k << " : ";
        for (int x : ans)
            cout << x << " ";
        cout << endl;
        return;
    }
    ans.push_back(a[i]);
    subsequences(i + 1, a, ans);
    ans.pop_back();
    subsequences(i + 1, a, ans);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t = 1;
    // cin >> t; // comment this line if your problem has 1 test case
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> ans;
        subsequences(0, a, ans);
    }
}