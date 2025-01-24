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
        int n, r, b;
        cin >> n >> r >> b;
        int x = b + 1;
        int y = r / x;
        int z = r % x;
        while(r!=0){
            for(int i = 0; i < y; i++){
                cout<<"R";
                r--;
            }
            if(z>0){
                cout<<"R";
                r--;
                z--;
            }
            if(r!=0){
                cout << "B";
            }
        
        }
        cout<<"\n";
    }
}