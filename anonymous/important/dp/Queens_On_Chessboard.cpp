#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

string board[8];
bool taken[8][8];

int rec(int level){
    if (level == 8)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        if (board[level][i] == '.' ){
            bool temp = true;
            for (int j = 0;j<level;j++){
                if (taken[j][i])
                {
                    temp = false;
                }
                else if (i - (level - j) >= 0 && taken[j][i - (level - j)])
                {
                    temp = false;
                }
                else if (i + (level - j) < 8 && taken[j][i + (level - j)])
                {
                    temp = false;
                }
            }
            if(temp){
                taken[level][i] = true;
                ans += rec(level + 1);
                taken[level][i] = false;
            }
        }
    }
    return ans;
}

int main()
{
    fastio for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }

    // for (int i = 0; i < 8; i++)
    // {
    //     cout << board[i] << endl;
    // }

    cout << rec(0) << endl;
}