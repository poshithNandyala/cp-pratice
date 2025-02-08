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
        multimap<int, int> mpa, mpb, mpc;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mpa.insert({x, i});
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mpb.insert({x, i});
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mpc.insert({x, i});
        }
        ll ans = 0, sum = 0;
        // Case 1: a->b->c
        auto it = mpa.end();
        it--;
        sum = it->first;
        int i = it->second;
        it = mpb.end();
        it--;
        while (it->second == i)
        {
            it--;
        }
        int j = it->second;
        sum += it->first;
        it = mpc.end();
        it--;
        while (it->second == i || it->second == j)
        {
            it--;
        }
        sum += it->first;
        ans = max(ans, sum);

        // Case 2: a->c->b
        sum = 0;
        it = mpa.end();
        it--;
        sum = it->first;
        i = it->second;
        it = mpc.end();
        it--;
        while (it->second == i)
        {
            it--;
        }
        j = it->second;
        sum += it->first;
        it = mpb.end();
        it--;
        while (it->second == i || it->second == j)
        {
            it--;
        }
        sum += it->first;
        ans = max(ans, sum);

        // Case 3: b->a->c
        sum = 0;
        it = mpb.end();
        it--;
        sum = it->first;
        i = it->second;
        it = mpa.end();
        it--;
        while (it->second == i)
        {
            it--;
        }
        j = it->second;
        sum += it->first;
        it = mpc.end();
        it--;
        while (it->second == i || it->second == j)
        {
            it--;
        }
        sum += it->first;
        ans = max(ans, sum);

        // Case 4: b->c->a
        sum = 0;
        it = mpb.end();
        it--;
        sum = it->first;
        i = it->second;
        it = mpc.end();
        it--;
        while (it->second == i)
        {
            it--;
        }
        j = it->second;
        sum += it->first;
        it = mpa.end();
        it--;
        while (it->second == i || it->second == j)
        {
            it--;
        }
        sum += it->first;
        ans = max(ans, sum);

        // Case 5: c->a->b
        sum = 0;
        it = mpc.end();
        it--;
        sum = it->first;
        i = it->second;
        it = mpa.end();
        it--;
        while (it->second == i)
        {
            it--;
        }
        j = it->second;
        sum += it->first;
        it = mpb.end();
        it--;
        while (it->second == i || it->second == j)
        {
            it--;
        }
        sum += it->first;
        ans = max(ans, sum);

        // Case 6: c->b->a
        sum = 0;
        it = mpc.end();
        it--;
        sum = it->first;
        i = it->second;
        it = mpb.end();
        it--;
        while (it->second == i)
        {
            it--;
        }
        j = it->second;
        sum += it->first;
        it = mpa.end();
        it--;
        while (it->second == i || it->second == j)
        {
            it--;
        }
        sum += it->first;
        ans = max(ans, sum);

        cout << ans << endl;
    }
}