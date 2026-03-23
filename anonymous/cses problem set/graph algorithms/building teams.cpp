#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> color(n + 1, -1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it : adj[node])
                {
                    if (color[it] == -1)
                    {
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    else if (color[it] == color[node])
                    {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)    {
        cout << color[i] + 1 << " ";
    }
    cout << endl;
}
