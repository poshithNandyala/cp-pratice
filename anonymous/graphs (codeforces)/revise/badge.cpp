/*
Problem: B. Badge

There are n students (1 to n).
Each student i points to exactly one student a[i].

If teacher starts from student i:
He goes to i → a[i] → a[a[i]] → ...
Eventually he will visit a student twice (because n is finite).

That student (first repeated) gets two holes.

Task:
For every student i (1 to n),
print which student gets two holes if teacher starts from i.

Key Idea:
This forms a functional graph (each node has one outgoing edge).
Every path eventually enters a cycle.
The answer is the first node where cycle is detected.

Optimization:
If we already computed answer for some node,
reuse it instead of recalculating.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // a[i] = student that i points to
    vector<int> a(n+1);

    // ans[i] = result if starting from i
    // -1 means not computed yet
    vector<int> ans(n+1, -1);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++){

        // If already solved earlier, skip
        if(ans[i] != -1)
            continue;

        int cur = i;

        // visited array for this traversal
        // used to detect cycle
        vector<int> vis(n+1, 0);

        // store traversal path
        vector<int> path;

        while(true){

            // CASE 1:
            // We reached a node whose answer is already known
            // So all nodes in current path will have same answer
            if(ans[cur] != -1){
                for(int x : path)
                    ans[x] = ans[cur];
                break;
            }

            // CASE 2:
            // We found a cycle (node visited again)
            if(vis[cur]){
                for(int x : path)
                    ans[x] = cur;  // cycle entry
                break;
            }

            // mark visited
            vis[cur] = 1;

            // store in path
            path.push_back(cur);

            // move to next node
            cur = a[cur];
        }
    }

    // print final answers
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}