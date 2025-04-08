// Include necessary header files
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Read number of test cases
    int t;
    cin >> t;
    while (t--)
    {
        // n is the input number, c counts found divisors
        int n, c = 0;
        // Vector to store the three divisors we find
        vector<int> a(3);
        cin >> n;
        
        // Try potential divisors starting from 2
        // Stop if we found 2 divisors or if i*i exceeds n
        for (int i = 2; i * i < n && c < 2; i++)
            // If i divides n evenly
            if (n % i == 0) {
                // Store the divisor and divide n by it
                a[c++] = i;
                n /= i;
            }
        
        // If we didn't find exactly 2 divisors, or if remaining n
        // is less than or equal to the last found divisor
        if (c != 2 || n <= a[1])
            cout << "NO" << endl;
        else
            // Print the three divisors: the two we found and the remaining n
            cout << "YES" << endl
                 << a[0] << " " << a[1] << " " << n << endl;
    }
}