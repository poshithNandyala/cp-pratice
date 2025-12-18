// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'
// #define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

// void make_spiral(int n, vector<vector<int>>& a) {
//     int turn = 2;
//     int i = 1, j = 0;
//     int v = 1;
//     a[0][0] = v++;
//     a[1][0] = v++;
//     a[1][1] = v++;
//     a[0][1] = v++;
//     while (i < n && j < n) {
//         if (j == 0) {
//             i++;
//             if (i >= n) break;
//             while (j <= turn) {
//                 a[i][j] = v++;
//                 j++;
//             }
//             while (i >= 0) {
//                 a[i][j] = v++;
//                 i--;
//             }
//             turn++;
//         }
//         if (i == 0) {
//             j++;
//             if (j >= n) break;
//             while (i <= turn) {
//                 a[i][j] = v++;
//                 i++;
//             }
//             while (j >= 0) {
//                 a[i][j] = v++;
//                 j--;
//             }
//             turn++;
//         }
//     }
// }

// int32_t main() {
//     fastio
//         int n = 5;
//     vector<vector<int>> a(n, vector<int>(n, 0));
//     make_spiral(n, a);
//     int t;
//     cin >> t;
//     while (t--) {
//         int x, y;
//         cin >> x >> y;
//         cout << a[x - 1][y - 1] << endl;
//     }
// }
