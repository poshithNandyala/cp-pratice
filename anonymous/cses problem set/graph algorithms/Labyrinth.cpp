#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int ai = 0, aj = 0, bi = 0, bj = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            else if (s[i][j] == 'B')
            {
                bi = i;
                bj = j;
                s[i][j] = '.';
            }
        }
    }

    queue<pair<int, int>> q;
    vector<pair<int, int>> dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};
    q.push({ai, aj});
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[ai][aj] = 0;
    while (!q.empty())
    {

        auto [i, j] = q.front();
        q.pop();
        for (auto it : dir)
        {
            int newi = i + it.first, newj = j + it.second;
            if (newi >= 0 && newi < s.size() && newj >= 0 && newj < s[0].size() && s[newi][newj] == '.')
            {
                if (dist[newi][newj] == -1)
                {
                    dist[newi][newj] = dist[i][j] + 1;
                    q.push({newi,newj});
                }
            }
        }
    }

    if (dist[bi][bj] != -1)
    {
        cout << "YES" << endl;
        cout << dist[bi][bj] << endl;
        int i = bi, j = bj;
        vector<char> ans;
        while (dist[i][j] != 0)
        {
            for (auto it : dir)
            {
                int newi = i + it.first, newj = j + it.second;
                if (newi >= 0 && newi < s.size() && newj >= 0 && newj < s[0].size() && dist[newi][newj] == dist[i][j] - 1)
                {
                    if (it.first == -1)
                    {
                        ans.push_back('D');
                        i = newi;
                        j = newj;
                        break;
                    }
                    else if (it.first == 1)
                    {
                        ans.push_back('U');
                        i = newi;
                        j = newj;
                        break;
                    }
                    else if (it.second == 1)
                    {
                        ans.push_back('L');
                        i = newi;
                        j = newj;
                        break;
                    }
                    else
                    {
                        ans.push_back('R');
                        i = newi;
                        j = newj;
                        break;
                    }
                }
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
        {
            cout << it;
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
