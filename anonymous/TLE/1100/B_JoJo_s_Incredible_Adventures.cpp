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
        string s;
        cin >> s;
        ll n = s.size();
        ll one = 0, c = 0,zero=0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zero++;
                one = max(one, c);
                c = 0;
            }
            else
            {
                c++;
            }
        }
        one=max(one,c);
        ll starting = 0, ending = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                break;
            }
            else{
                starting++;
            }
        }
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                break;
            }
            else{
                ending++;
            }
        }
        if(starting >0 && ending > 0 && zero >= 1) {
            one = max(one, starting + ending);
        }
        // cout << "one" << one << endl;
        if(one==n){
            cout<<one*one<<endl;
        }
        else if(one==1){
            cout<<one<<endl;
        }
        else{
            one += 1;
            cout<<(one/2)*(one-(one/2))<<endl;
        }
    }
}