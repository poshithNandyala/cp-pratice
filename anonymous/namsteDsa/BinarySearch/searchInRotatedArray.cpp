class Solution {
public:
    int search(vector<int>& a, int x) {
        int lo = 0, hi = a.size() - 1;

        while (lo <= hi) {
            // Calculate mid safely to avoid overflow
            int mid = lo + (hi - lo) / 2;

            // If target found, return index
            if (a[mid] == x)
                return mid;

            // Check if left half [lo..mid] is sorted
            if (a[lo] <= a[mid]) {

                // If target lies in the sorted left half
                if (a[lo] <= x && x < a[mid])
                    hi = mid - 1;   // search left
                else
                    lo = mid + 1;   // search right
            }
            // Otherwise, right half [mid..hi] is sorted
            else {

                // If target lies in the sorted right half
                if (a[mid] < x && x <= a[hi])
                    lo = mid + 1;   // search right
                else
                    hi = mid - 1;   // search left
            }
        }

        // Target not found
        return -1;
    }
};
