class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();

        // If only one element, it is the peak
        if (n == 1) return 0;

        // Check boundary elements separately
        if (a[0] > a[1]) return 0;
        if (a[n - 1] > a[n - 2]) return n - 1;

        int lo = 1, hi = n - 2;

        // Binary search on the remaining elements
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Case 1: mid is a peak
            if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
                return mid;
            }

            // Case 2: descending slope → peak exists on the left
            else if (a[mid] > a[mid + 1]) {
                hi = mid - 1;
            }

            // Case 3: ascending slope → peak exists on the right
            else {
                lo = mid + 1;
            }
        }

        return -1; // This line is never reached
    }
};
