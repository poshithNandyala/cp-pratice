#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// Function to find the single non-duplicate element using binary search
int singleNonDuplicate(vector<int>& arr) {
    // Get the size of the array
    int n = arr.size();

    // Edge case: only one element in the array
    if (n == 1) return arr[0];

    // Edge case: first element is the unique one
    if (arr[0] != arr[1]) return arr[0];

    // Edge case: last element is the unique one
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    // Initialize binary search bounds (exclude first and last index)
    int low = 1, high = n - 2;

    // Perform binary search
    while (low <= high) {
        // Calculate middle index
        int mid = (low + high) / 2;

        // Check if middle element is the unique one
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        // If mid is in the left half (pairing is valid)
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            // Move to the right half
            low = mid + 1;
        }
        // If mid is in the right half (pairing broken earlier)
        else {
            // Move to the left half
            high = mid - 1;
        }
    }

    // Dummy return (not reachable if input is valid)
    return -1;
   }
};

// Driver code
int main() {
    // Input array with all elements appearing twice except one
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // Call the function and store the result
    Solution obj;
    
    int ans = obj.singleNonDuplicate(arr);

    // Print the result
    cout << "The single element is: " << ans << "\n";

    return 0;
}
