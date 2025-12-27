#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int digits = 1;
        int count = 9;
        int start = 1;
        while(n> start + count*digits -1){
            start+=count*digits;
            count *= 10;
            digits++;
        }
        int st=pow(10,digits-1);
        int num_offset = (n - start) / digits;
        int num = st + num_offset;
        int digit_offset = (n - start) % digits;
        cout<<to_string(num)[digit_offset]<<endl;
    }
    return 0;
}
