// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'
// #define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

// int32_t main() {
//     fastio
//         int n;
//     cin >> n;
//     if (n >= 2 && n <= 3) {
//         cout << "NO SOLUTION" << endl;
//     }
//     else if(n==4){
//         cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl;
//     }
//     else {
//         int s = 1, t = (n+1)/2 + 1;
//         for (int i = 1;i <= n;i++) {
//             if (i % 2) {
//                 cout << s++ << " ";
//             }
//             else {
//                 cout << t++ << " ";
//             }
//         }
//     }

// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    // print even numbers
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";

    // print odd numbers
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";

    cout << '\n';
    return 0;
}
