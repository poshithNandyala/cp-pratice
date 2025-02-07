#include <bits/stdc++.h>

using namespace std;
#define int int64_t

main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        set<int> st;
        for (int i = 0; i < n; ++i)
            cin >> a[i], st.insert(a[i]);
        for (int x : a)
            if (st.count(x + k))
            {
                cout << "YES\n";
                goto done;
            }
        cout << "NO\n";
    done:;
    }
}
