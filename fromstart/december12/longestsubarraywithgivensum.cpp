#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Implement this function (your solution) — array contains only positive integers.
    // nums : input array
    // k    : target sum
    // Return the length of the longest subarray with sum == k (or 0 / -1 as you prefer if none).
    int solution(vector<int>& nums, int k) {
        
        return 0;
    }
};

/*
LeetCode-style notes:
- You can rename `solution` to the exact LeetCode function name if needed.
- The online judge will call the method on class `Solution`.
- The main below is only for local testing; LeetCode does not require it.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Local test harness (reads n k then n numbers)
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    Solution sol;
    cout << sol.solution(nums, k) << '\n';
    return 0;
}
