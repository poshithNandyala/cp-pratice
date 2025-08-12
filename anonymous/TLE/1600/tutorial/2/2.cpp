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
        
        // Result will be product of ways for each digit
        int result = 1;
        
        // Process each digit of n from right to left
        while (n > 0) {
            int digit = n % 10;  // Current digit
            n /= 10;
            
            // Count ways to form triplets (a,b,c) such that a+b+c = digit
            // where a,b,c are single digits (0-9) and no carry occurs
            int ways = 0;
            for (int a = 0; a <= 9; a++) {
                for (int b = 0; b <= 9; b++) {
                    for (int c = 0; c <= 9; c++) {
                        // Check if a+b+c equals current digit (no carry)
                        if (a + b + c == digit) {
                            ways++;
                        }
                    }
                }
            }
            
            // Multiply result by ways for this digit position
            result *= ways;
        }
        
        cout << result << endl;
    }
}
