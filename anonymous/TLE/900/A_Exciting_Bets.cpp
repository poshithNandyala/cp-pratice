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
        ll a, b;
        cin >> a >> b;
        if(a == b){
            cout << "0 0" << endl;
        }else{
            if(a < b) swap(a, b);
            ll delta = a - b;
            cout << delta << " " << min(b % delta, delta - b % delta) << endl;
        }
    }
}

// Let me help prove why this statement is true by thinking through it step by step.

// 1. First, let's understand what we need to prove:
//    If a > b, then gcd(a,b) = gcd(a-b,b)

// 2. Let's call gcd(a,b) = d
//    This means:
//    - d divides both a and b
//    - d is the largest such number
//    - We can write: a = md and b = nd for some integers m,n

// 3. Now, if d divides both a and b, then:
//    - d must also divide (a-b)
//    - Because a-b = md - nd = (m-n)d

// 4. Therefore, d is a common divisor of (a-b) and b

// 5. But we need to prove it's the greatest common divisor
//    Let's say there exists a larger common divisor d' of (a-b) and b
//    Then:
//    - d' divides (a-b) and b
//    - Therefore d' must also divide (a-b) + b = a
//    - So d' divides both a and b
//    - But this contradicts our assumption that d was the gcd of a and b

// 6. Therefore, d must be the greatest common divisor of (a-b) and b

// Thus, gcd(a,b) = gcd(a-b,b) when a > b.

// This proof shows why we can use subtraction instead of division in algorithms like the Euclidean algorithm for finding GCD.