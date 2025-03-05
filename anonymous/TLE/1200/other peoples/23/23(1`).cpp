#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200000
using namespace std;
void build_add(vector<string> &v, int n)
{
    int ALF = 26;
    int p = pow(ALF, n);
    for (int i = 0; i < p; ++i)
    {
        int j = i;
        string s = "";
        for (int k = 0; k < n; ++k)
        {
            s += j % ALF + 'a';
            j /= ALF;
        }
        while (j > 0)
            ;
        reverse(s.begin(), s.end());
        v.push_back(s);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    for (int i = 1; i <= 3; ++i)
        build_add(v, i);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0;; ++i)
        {
            if (s.find(v[i]) == -1)
            {
                cout << v[i] << endl;
                break;
            }
        }
    }
    return 0;
}
