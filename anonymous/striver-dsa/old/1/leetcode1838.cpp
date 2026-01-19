#include <bits/stdc++.h>
using namespace std;

/*
Problem 1838. Frequency of the Most Frequent Element

Given an array nums and integer k, in one operation we can choose an index and increment that element by 1.
Return the maximum possible frequency of an element after at most k operations.

Example:
nums = [1,2,4], k = 5
Output: 3
We can increment 1->4 (3 ops) and 2->4 (2 ops) to make [4,4,4]
So 4 appears with frequency 3

Approach:
1. Sort array to group similar elements together
2. Use sliding window technique:
   - Window represents elements we try to make equal to current target
   - Target is the rightmost element in window
   - Track sum of elements in window to calculate operations needed
   - If operations needed > k, shrink window from left
   - Window size represents frequency we can achieve
3. Return max window size found
*/

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        // Sort array to group similar elements
        sort(nums.begin(), nums.end());

        int left = 0;  // Left pointer of sliding window
        int ans = 0;   // Max frequency found so far
        long curr = 0; // Sum of elements in current window

        // Iterate right pointer of window
        for (int right = 0; right < nums.size(); right++)
        {
            long target = nums[right]; // Try to make all elements equal to this
            curr += target;            // Add new element to window sum

            // If operations needed exceeds k, shrink window
            while ((right - left + 1) * target - curr > k)
            {
                curr -= nums[left]; // Remove leftmost element from sum
                left++;             // Shrink window from left
            }

            // Update max frequency found
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int k, n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter k: ";
    cin >> k;

    int result = solution.maxFrequency(nums, k);
    cout << "Maximum frequency after operations: " << result << endl;

    return 0;
}