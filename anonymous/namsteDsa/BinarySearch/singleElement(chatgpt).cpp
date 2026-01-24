class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int lo = 0, hi = a.size() - 1;

        // Binary search on indices
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // Ensure mid is even so we compare pairs correctly
            if (mid % 2 == 1)
                mid--;

            // If pair is correct, single element is on right side
            if (a[mid] == a[mid + 1]) {
                lo = mid + 2;
            }
            // Pair is broken, single element is on left side (including mid)
            else {
                hi = mid;
            }
        }

        // lo == hi pointing to the single element
        return a[lo];
    }
};
