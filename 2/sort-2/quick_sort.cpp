/*
Quick Sort Algorithm

Quick Sort is a divide-and-conquer sorting algorithm that picks an element as a pivot
and partitions the array around it such that smaller elements move before the pivot
and larger elements after it.

Algorithm:
1. Choose a pivot element from the array
2. Partition array around pivot - elements smaller than pivot go left, larger go right
3. Recursively sort the sub-arrays on left and right of pivot
4. Combine the sorted sub-arrays

Example:
Initial array: [10, 7, 8, 9, 1, 5]
Choose pivot=5:
Partition: [1] [5] [10,7,8,9]
Recursively sort subarrays:
Left of 5: [1]
Right of 5: [7] [8] [9,10]
Result: [1, 5, 7, 8, 9, 10]

Time Complexity:
- Best Case: O(n log n) - When pivot divides array in equal halves
- Average Case: O(n log n)
- Worst Case: O(n^2) - When array is already sorted

Space Complexity: O(log n) - Due to recursion stack

Characteristics:
- In-place sorting algorithm
- Unstable algorithm
- Very efficient on average
- Good cache performance
- Widely used in practice
- Parallelizable
*/

/*
             Timestamp  : 13:22 - Monday  31,Mar 2025
*/
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int pindex = partition(arr, low, high);
    quicksort(arr, low, pindex - 1);
    quicksort(arr, pindex + 1, high);
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}