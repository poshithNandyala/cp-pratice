#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int x;
    int id;
} A[200050], B[200050], C[200050];
bool cmp(node a, node b)
{
    if (a.x > b.x)
        return 1;
    else
        return 0;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i].x;
            A[i].id = i;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> B[i].x;
            B[i].id = i;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> C[i].x;
            C[i].id = i;
        }

        sort(A + 1, A + 1 + n, cmp);
        sort(B + 1, B + 1 + n, cmp);
        sort(C + 1, C + 1 + n, cmp);
        int mx = 0;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (A[i].id == B[j].id || A[i].id == C[k].id || B[j].id == C[k].id)
                        continue;
                    else
                        mx = max(mx, A[i].x + B[j].x + C[k].x);
                }
            }
        }
        cout << mx << endl;
    }
    return 0;
}