/*
Merge Sort Algorithm

Merge Sort is a divide-and-conquer sorting algorithm that recursively divides the input array into two halves,
sorts them, and then merges the sorted halves to produce a final sorted array.

Algorithm:
1. Divide array into two halves recursively until size becomes 1
2. Sort each half recursively using merge sort
3. Merge the sorted halves by comparing elements
4. Use auxiliary space to store merged result

Example:
Initial array: [38, 27, 43, 3, 9, 82, 10]
Divide: [38, 27, 43, 3] and [9, 82, 10]
Further divide: [38, 27] [43, 3] [9, 82] [10]
Sort and merge: [27, 38] [3, 43] [9, 82] [10]
Final merge: [3, 27, 38, 43] [9, 10, 82]
Result: [3, 9, 10, 27, 38, 43, 82]

Time Complexity:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

Space Complexity: O(n) - Requires auxiliary space

Characteristics:
- Stable sorting algorithm
- Not in-place - requires extra space
- Predictable performance - always O(n log n)
- Parallelizable - different parts can be sorted concurrently
- Preferred for sorting linked lists
- Used as base for many other algorithms
*/
/*
             Timestamp  : 12:40 - Monday  31,Mar 2025
*/
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int temp[r - l + 1];
    int i = 0, left = l, right = m + 1;

    while (left <= m && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp[i++] = arr[left++];
        }
        else
        {
            temp[i++] = arr[right++];
        }
    }

    while (left <= m)
    {
        temp[i++] = arr[left++];
    }

    while (right <= r)
    {
        temp[i++] = arr[right++];
    }

    for (int k = 0; k < i; k++)
    {
        arr[l + k] = temp[k];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
