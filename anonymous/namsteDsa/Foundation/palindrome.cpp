bool isPalindrome(int x) {
    // Case 1: If number is negative, it can never be a palindrome
    // Example: -121 (because of the minus sign)
    // Case 2: If number ends with 0 but is not 0 itself
    // Example: 10 -> reverse would be 01 (invalid)
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    // This variable will store the reversed second half of the number
    int rev = 0;

    // We reverse digits only until rev becomes >= x
    // This means we have processed HALF of the number
    while (x > rev) {
        // Take last digit of x and add it to rev
        // Example: x = 123
        // rev = 0*10 + 3 = 3
        rev = rev * 10 + x % 10;

        // Remove last digit from x
        // Example: x = 123 -> 12
        x /= 10;
    }

    // Two cases:
    // 1) Even number of digits:
    //    Example: 1221 -> x = 12, rev = 12
    // 2) Odd number of digits:
    //    Example: 12321 -> x = 12, rev = 123
    //    We remove the middle digit by rev / 10
    return x == rev || x == rev / 10;
}
