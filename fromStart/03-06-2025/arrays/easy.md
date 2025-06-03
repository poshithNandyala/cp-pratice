Certainly! Let's delve into each problem from the Striver DSA Sheet, exploring the brute force, better, and optimal approaches with detailed explanations and intuitions.

---

### 1. **Largest Element in an Array**

**Problem Statement:**
Given an array, find the largest element.

**Brute Force Approach:**

- **Idea:** Compare each element with every other element to find the maximum.
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)([stackoverflow.com][1], [geeksforgeeks.org][2])

**Optimal Approach:**

- **Idea:** Traverse the array once, keeping track of the maximum element found so far.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Intuition:**
By iterating through the array once and updating the maximum when a larger element is found, we efficiently find the largest element.

---

### 2. **Second Largest Element in an Array without Sorting**

**Problem Statement:**
Find the second largest element in the array without sorting.

**Brute Force Approach:**

- **Idea:** Find the largest element, remove it, then find the largest in the remaining array.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Better Approach:**

- **Idea:** Traverse the array twice: first to find the largest, second to find the largest less than the maximum.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)([geeksforgeeks.org][3])

**Optimal Approach:**

- **Idea:** Traverse the array once, maintaining both the largest and second largest elements.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Intuition:**
By keeping track of the top two maximums during a single traversal, we efficiently find the second largest element.([geeksforgeeks.org][3])

---

### 3. **Check if the Array is Sorted**

**Problem Statement:**
Determine if the array is sorted in non-decreasing order.

**Brute Force Approach:**

- **Idea:** Compare each pair of elements to ensure the previous is less than or equal to the next.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Optimal Approach:**

- **Idea:** Traverse the array once, checking if any element is greater than the next.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Intuition:**
A single pass is sufficient to verify the sorted order by comparing adjacent elements.

---

### 4. **Remove Duplicates from Sorted Array**

**Problem Statement:**
Remove duplicates in-place from a sorted array.

**Brute Force Approach:**

- **Idea:** Use a set to store unique elements and overwrite the array.
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)([linkedin.com][4])

**Optimal Approach:**

- **Idea:** Use two pointers to overwrite duplicates.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)([algo.monster][5])

**Intuition:**
By using two pointers, we can overwrite duplicates in-place without extra space.([takeuforward.org][6])

---

### 5. **Left Rotate an Array by One Place**

**Problem Statement:**
Rotate the array to the left by one position.

**Brute Force Approach:**

- **Idea:** Use a temporary array to store rotated elements.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)([geeksforgeeks.org][7])

**Optimal Approach:**

- **Idea:** Store the first element, shift all elements left by one, and place the first element at the end.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Intuition:**
Shifting elements in-place and repositioning the first element achieves the rotation efficiently.

---

### 6. **Left Rotate an Array by D Places**

**Problem Statement:**
Rotate the array to the left by D positions.

**Brute Force Approach:**

- **Idea:** Rotate the array by one position D times.
- **Time Complexity:** O(n\*D)
- **Space Complexity:** O(1)([linkedin.com][4])

**Better Approach:**

- **Idea:** Use a temporary array to store the first D elements, shift the rest, and append the stored elements at the end.
- **Time Complexity:** O(n)
- **Space Complexity:** O(D)

**Optimal Approach:**

- **Idea:** Use the reversal algorithm: reverse the first D elements, reverse the remaining, then reverse the entire array.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)([geeksforgeeks.org][7])

**Intuition:**
Reversing parts of the array strategically achieves the desired rotation without extra space.

---

### 7. **Move Zeros to End**

**Problem Statement:**
Move all zeros in the array to the end while maintaining the order of non-zero elements.

**Brute Force Approach:**

- **Idea:** Create a new array, copy non-zero elements, then append zeros.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

**Optimal Approach:**

- **Idea:** Use two pointers to swap non-zero elements forward, filling zeros at the end.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Intuition:**
By moving non-zero elements forward and filling the rest with zeros, we achieve the goal in-place.([geeksforgeeks.org][2])

---

### 8. **Linear Search**

**Problem Statement:**
Find the index of a target element in the array.

**Brute Force Approach:**

- **Idea:** Traverse the array and compare each element with the target.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Intuition:**
A straightforward approach where each element is checked until the target is found.([takeuforward.org][8])

---

### 9. **Find the Union**

**Problem Statement:**
Find the union of two arrays.

**Brute Force Approach:**

- **Idea:** Concatenate both arrays and remove duplicates using a set.
- **Time Complexity:** O((m+n) log(m+n))
- **Space Complexity:** O(m+n)([linkedin.com][4], [blog.masum.dev][9])

**Optimal Approach:**

- **Idea:** If arrays are sorted, use two pointers to merge them while skipping duplicates.
- **Time Complexity:** O(m+n)
- **Space Complexity:** O(m+n)([blog.masum.dev][9])

**Intuition:**
Merging sorted arrays while avoiding duplicates provides an efficient union.

---

### 10. **Find Missing Number in an Array**

**Problem Statement:**
Find the missing number in an array containing numbers from 1 to N.

**Brute Force Approach:**

- **Idea:** Check for each number from 1 to N if it's present in the array.
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)([takeuforward.org][10])

**Better Approach:**

- **Idea:** Use a hash set to store elements and check for the missing one.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

**Optimal Approach:**

- **Idea:** Calculate the expected sum of numbers from 1 to N and subtract the actual sum.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Intuition:**
The difference between the expected and actual sums reveals the missing number.

---

### 11. **Maximum Consecutive Ones**

**Problem Statement:**
Find the maximum number of consecutive 1s in a binary array.

**Brute Force Approach:**

- **Idea:** Check every subarray and count the maximum consecutive 1s.
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)

**Optimal Approach:**

- **Idea:** Traverse the array, counting consecutive 1s and updating the maximum.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Intuition:**
By counting consecutive 1s in a single pass, we efficiently find the maximum streak.

---

[1]: https://stackoverflow.com/questions/51813509/finding-the-second-largest-element-in-array-without-sorting?utm_source=chatgpt.com "Finding the second largest element in array without sorting"
[2]: https://www.geeksforgeeks.org/move-zeroes-end-array/?utm_source=chatgpt.com "Move all zeros to end of array | GeeksforGeeks"
[3]: https://www.geeksforgeeks.org/find-second-largest-element-array/?utm_source=chatgpt.com "Second Largest Element in an Array | GeeksforGeeks"
[4]: https://www.linkedin.com/posts/satyam-jha2004_day-33-of-dsa-from-strivers-sde-sheet-activity-7302723699147751424-I6jy?utm_source=chatgpt.com "Satyam Jha - Day 33 of DSA from Striver's SDE Sheet - LinkedIn"
[5]: https://algo.monster/liteproblems/80?utm_source=chatgpt.com "80. Remove Duplicates from Sorted Array II - In-Depth Explanation"
[6]: https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/?utm_source=chatgpt.com "Remove Duplicates in-place from Sorted Array - takeUforward"
[7]: https://www.geeksforgeeks.org/array-rotation/?utm_source=chatgpt.com "Rotate an Array by d – Counterclockwise or Left | GeeksforGeeks"
[8]: https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/?utm_source=chatgpt.com "Search Single Element in a sorted array - Tutorial - takeUforward"
[9]: https://blog.masum.dev/how-to-remove-duplicates-from-a-sorted-array?utm_source=chatgpt.com "Remove Duplicates from Sorted Array - Masum's Blog"
[10]: https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/?utm_source=chatgpt.com "Majority Elements(>N/3 times) - takeUforward"

Certainly! Let's delve into the remaining problems from the Striver DSA Sheet, providing detailed explanations and approaches for each.

---

### 12. **Find the Number that Appears Once, and Other Numbers Twice**

**Problem Statement:**
Given an array where every element appears twice except for one, find the element that appears only once.([leetcode.com][1])

**Brute Force Approach:**

- **Idea:** For each element, count its occurrences by traversing the entire array. The element with a count of one is the unique element.
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)([medium.com][2])

**Better Approach:**

- **Idea:** Use a hash map to count the frequency of each element. Then, iterate through the map to find the element with a frequency of one.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

**Optimal Approach:**

- **Idea:** Utilize the XOR operation. XOR of a number with itself is 0, and XOR of a number with 0 is the number itself. XOR all elements; the result will be the unique element.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)([geeksforgeeks.org][3])

**Intuition:**
Pairs of identical numbers will cancel each other out when XORed, leaving the unique number as the result.

**Example:**
Input: \[4, 1, 2, 1, 2]
Output: 4([takeuforward.org][4])

This approach is efficient and commonly used in such scenarios.&#x20;

---

### 13. **Longest Subarray with Given Sum K (Positives Only)**

**Problem Statement:**
Given an array of positive integers, find the length of the longest subarray whose sum equals K.([naukri.com][5])

**Brute Force Approach:**

- **Idea:** Generate all possible subarrays and calculate their sums to find the maximum length subarray with sum K.
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)([medium.com][2])

**Better Approach:**

- **Idea:** Use a sliding window technique. Initialize two pointers and a sum variable. Expand the window by moving the right pointer and shrink it by moving the left pointer based on the sum compared to K.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Optimal Approach:**

- **Idea:** The sliding window approach is optimal for arrays with only positive numbers, as the sum will always increase when adding new elements.

**Intuition:**
Since all numbers are positive, increasing the window size increases the sum, and decreasing it reduces the sum, making the sliding window approach effective.

**Example:**
Input: \[1, 2, 3, 1, 1, 1, 1], K = 3
Output: 3([geeksforgeeks.org][6])

This method efficiently finds the desired subarray length. ([geeksforgeeks.org][6])

---

### 14. **Longest Subarray with Sum K (Positives and Negatives)**

**Problem Statement:**
Given an array containing both positive and negative integers, find the length of the longest subarray whose sum equals K.([leetcode.com][7])

**Brute Force Approach:**

- **Idea:** Generate all possible subarrays and calculate their sums to find the maximum length subarray with sum K.
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)([medium.com][2])

**Optimal Approach:**

- **Idea:** Use a hash map to store the cumulative sum and its earliest index. For each element, calculate the cumulative sum. If (current sum - K) exists in the map, update the maximum length.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)([algo.monster][8])

**Intuition:**
By storing the earliest occurrence of each cumulative sum, we can efficiently find subarrays that sum to K, even with negative numbers.([geeksforgeeks.org][9])

**Example:**
Input: \[10, 5, 2, 7, 1, -10], K = 15
Output: 4([geeksforgeeks.org][6])

This approach handles negative numbers effectively.&#x20;

---

If you need further assistance or explanations on any other problems, feel free to ask!

[1]: https://leetcode.com/problems/single-number/?utm_source=chatgpt.com "Single Number - LeetCode"
[2]: https://medium.com/%40arshilazeem5/longest-subarray-with-sum-k-positives-negatives-9a5f50d84a43?utm_source=chatgpt.com "Longest subarray with sum k (positives + negatives) | by Arshil Azeem"
[3]: https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/?utm_source=chatgpt.com "Unique Number I | GeeksforGeeks"
[4]: https://takeuforward.org/arrays/find-the-number-that-appears-once-and-the-other-numbers-twice/?utm_source=chatgpt.com "Find the number that appears once, and the other numbers twice"
[5]: https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?utm_source=chatgpt.com "Longest Subarray With Sum K - Naukri Code 360"
[6]: https://www.geeksforgeeks.org/longest-sub-array-sum-k/?utm_source=chatgpt.com "Longest Subarray With Sum K | GeeksforGeeks"
[7]: https://leetcode.com/discuss/interview-question/758045/apple-phone-longest-subarray-sum-at-most-k?utm_source=chatgpt.com "Apple | Phone | Longest Subarray Sum At Most K - LeetCode Discuss"
[8]: https://algo.monster/liteproblems/325?utm_source=chatgpt.com "325. Maximum Size Subarray Sum Equals k - In-Depth Explanation"
[9]: https://www.geeksforgeeks.org/find-subarray-with-given-sum/?utm_source=chatgpt.com "Subarray with Given Sum | GeeksforGeeks"
