#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

int main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1);
        a[0] = 0; 
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i]^= a[i-1];
        }
        bool yes = !a[n];
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j < n; j++) {
                yes |= (a[i] == (a[j]^a[i]) && a[i] == (a[n]^a[j]));
            }
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
}