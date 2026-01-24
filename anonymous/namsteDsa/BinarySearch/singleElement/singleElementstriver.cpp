class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();

        // Edge cases
        if (n == 1) return a[0];
        if (a[0] != a[1]) return a[0];
        if (a[n-1] != a[n-2]) return a[n-1];

        int lo = 1, hi = n - 2;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // If mid is the single element
            if (a[mid] != a[mid-1] && a[mid] != a[mid+1]) {
                return a[mid];
            }

            /*
             Before the single element:
             - even index -> pair starts at even
             - odd index  -> pair ends at odd

             After the single element:
             - pattern breaks
            */

            // If we're still on the "correct pair side"
            if ((mid % 2 == 0 && a[mid] == a[mid + 1]) ||
                (mid % 2 == 1 && a[mid] == a[mid - 1])) {
                lo = mid + 1;   // move right
            } 
            else {
                hi = mid - 1;   // move left
            }
        }

        return -1; // never reached for valid input
    }
};
