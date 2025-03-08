#include <iostream>

int main()
{
    // Optimize input/output operations
    std::ios_base::sync_with_stdio(false);

    // Number of test cases
    long t;
    std::cin >> t;

    while (t--)
    {
        // Length of strings a and b
        long n;
        std::cin >> n;

        // Input strings a and b
        std::string a, b;
        std::cin >> a >> b;

        // Add an extra '0' to both strings to handle boundary checking
        // This is a clever trick to avoid special handling for the last character
        a += '0';
        b += '0';

        // cnt will track the balance of 1s and 0s in the current prefix
        // cnt = (number of 1s) - (number of 0s)
        long cnt(0);

        // Flag to track if transformation is possible
        bool ans(true);

        // Iterate through each position in the string
        for (long p = 0; p < a.size(); p++)
        {
            // Update the balance: +1 for each '1', -1 for each '0'
            cnt += (a[p] == '1') - (a[p] == '0');

            // Key insight: If we can flip a prefix, then a and b should match
            // or not match consistently within each valid "flippable section"

            // Check if there's an inconsistency in matching pattern at adjacent positions
            // AND there's a non-zero balance (which means we have a valid prefix to flip)
            // (a[p] == b[p]) checks if current characters match
            // (a[p+1] == b[p+1]) checks if next characters match
            // If one pair matches and the other doesn't, the XOR operation (!= operator) will be true
            // The additional condition (cnt) checks if we have a balanced prefix (cnt=0) which we can flip
            if ((a[p] == b[p]) != (a[p + 1] == b[p + 1]) && cnt)
            {
                // If inconsistency is found and cnt is not 0, transformation is impossible
                ans = false;
                break;
            }
        }

        // Output the result
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
}