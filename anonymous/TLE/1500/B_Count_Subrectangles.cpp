// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'
// #define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);


// int anss(int a, int b, vector<int>& div, int k) {
//     // cout << "a: " << a << " b: " << b << " k: " << k << endl;
//     int ans = 0;
//     for (int i = 0; i < div.size(); i++) {
//         if (a >= div[i]) {
//             if (b >= (k / div[i])) {
//                 ans += (div[i] - a - 1) * ((k / div[i]) - b - 1);
//             }
//         }
//         else {
//             break;
//         }
//     }
//     return ans;
// }
// int32_t main() {
//     fastio

//         int n, m, k;
//     cin >> n >> m >> k;
//     // vector<int> a(n), b(m);
//     vector<int> aa, bb, div;
//     for (int i = 1;i <= sqrt(k);i++) {
//         if (k % i == 0) {
//             div.push_back(i);
//             if (k / i != i) {
//                 div.push_back(k / i);
//             }
//         }
//     }
//     sort(div.begin(), div.end());
//     int c = 0;
//     for (int i = 0; i < n; i++) {
//         int a;
//         cin >> a;
//         if (a == 1) {
//             c++;
//         }
//         else if (c) {
//             aa.push_back(c);
//             c = 0;
//         }
//     }
//     if (c) {
//         aa.push_back(c);
//         c = 0;
//     }
//     for (int i = 0; i < m; i++) {
//         int b;
//         cin >> b;
//         if (b == 1) {
//             c++;
//         }
//         else if (c) {
//             bb.push_back(c);
//             c = 0;
//         }
//     }
//     if (c) {
//         bb.push_back(c);
//         c = 0;
//     }
//     int ans = 0;
//     // vector<pair<int, int>> v;
//     for (int i = 0; i < aa.size(); i++) {
//         for (int j = 0; j < bb.size(); j++) {
//             if (aa[i] * bb[j] >= k) {
//                 ans += anss(aa[i], bb[j], div, k);
//                 // v.push_back({ aa[i], bb[j] });
//             }
//         }
//     }
//     // for (auto item : div) {
//     //     cout << item << " ";
//     // }
//     // cout << "\n";

//     // for (auto item : v) {
//     //     cout << item.first << " " << item.second << endl;
//     // }
//     // cout << "\n";

//     cout << ans << endl;

// }
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> aa, bb;
    int c = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) c++;
        else if (c) aa.push_back(c), c = 0;
    }
    if (c) aa.push_back(c), c = 0;

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        if (b == 1) c++;
        else if (c) bb.push_back(c), c = 0;
    }
    if (c) bb.push_back(c), c = 0;

    map<int, int> row_count, col_count;
    for (int len : aa)
        for (int d = 1; d <= len; d++)
            row_count[d] += (len - d + 1);

    for (int len : bb)
        for (int d = 1; d <= len; d++)
            col_count[d] += (len - d + 1);

    vector<int> div;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            div.push_back(i);
            if (i != k / i) div.push_back(k / i);
        }
    }

    int ans = 0;
    for (int i = 0; i < div.size(); i++) {
        int d1 = div[i], d2 = k / d1;
        if (row_count.count(d1) && col_count.count(d2))
            ans += row_count[d1] * col_count[d2];
    }

    cout << ans << endl;
}
