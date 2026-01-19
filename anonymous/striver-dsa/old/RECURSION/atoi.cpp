#include <iostream>
#include <climits>  // For INT_MAX and INT_MIN
#include <cctype>   // For isdigit and isspace
#include <string>   // For std::string

using namespace std;

/*
    Problem: 8. String to Integer (atoi)

    Description:
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
    
    Steps of the algorithm:
    1. Skip all leading whitespaces.
    2. Check for optional '+' or '-' to determine the sign.
    3. Skip leading zeros.
    4. Read digits and convert to integer until a non-digit is encountered.
    5. Clamp the value if it goes outside the 32-bit signed integer range [-2^31, 2^31 - 1].
    6. Return the result with the appropriate sign.
    
    Example Inputs and Expected Outputs:
    -------------------------------------
    Input:  "42"               → Output: 42
    Input:  "   -042"          → Output: -42
    Input:  "1337c0d3"         → Output: 1337
    Input:  "0-1"              → Output: 0
    Input:  "words and 987"    → Output: 0
    Input:  "-91283472332"     → Output: -2147483648 (clamped)
*/

/*
    Function: parseDigits
    ---------------------
    Recursively parses digits from the string starting at index and constructs the result.
    - Stops on reaching a non-digit character or the end of string.
    - Applies the sign and clamps to 32-bit integer range if necessary.
*/
int parseDigits(const string& s, int index, long long result, int sign) {
    if (index >= s.size() || !isdigit(s[index]))
        return sign * static_cast<int>(result);

    result = result * 10 + (s[index] - '0');

    // Clamp if value goes out of 32-bit signed int bounds
    if (sign == 1 && result >= INT_MAX) return INT_MAX;
    if (sign == -1 && -result <= INT_MIN) return INT_MIN;

    return parseDigits(s, index + 1, result, sign);
}

/*
    Function: myAtoi
    ----------------
    Parses the string and returns its integer representation using recursive digit parsing.
*/
int myAtoi(string s) {
    int i = 0;
    int n = s.size();

    // Step 1: Skip leading whitespace
    while (i < n && s[i] == ' ') i++;

    // Step 2: Detect optional sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Skip leading zeros
    while (i < n && s[i] == '0') i++;

    // Step 4: Parse digits recursively
    return parseDigits(s, i, 0, sign);
}

// Driver code for testing
int main() {
    // Test cases
    cout << myAtoi("42") << endl;             // Output: 42
    cout << myAtoi("   -042") << endl;        // Output: -42
    cout << myAtoi("1337c0d3") << endl;       // Output: 1337
    cout << myAtoi("0-1") << endl;            // Output: 0
    cout << myAtoi("words and 987") << endl;  // Output: 0
    cout << myAtoi("-91283472332") << endl;   // Output: -2147483648 (clamped)

    return 0;
}
