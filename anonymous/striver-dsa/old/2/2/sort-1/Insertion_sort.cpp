/*
Insertion sort

Insertion sort works by building a sorted array one element at a time.
It takes each element from the unsorted portion and inserts it into its correct position in the sorted portion.

Steps:
1. Start with first element as sorted portion of size 1
2. Take next element from unsorted portion
3. Compare with each element in sorted portion from right to left
4. Insert element in correct position by shifting larger elements right
5. Repeat steps 2-4 until all elements are sorted

Example:
Initial array: [64, 34, 25, 12, 22]
Pass 1: [34, 64, 25, 12, 22] - Insert 34 before 64
Pass 2: [25, 34, 64, 12, 22] - Insert 25 before 34
Pass 3: [12, 25, 34, 64, 22] - Insert 12 at start
Pass 4: [12, 22, 25, 34, 64] - Insert 22 after 12

Time Complexity:
- Best Case: O(n) - When array is already sorted
- Average Case: O(n^2)
- Worst Case: O(n^2) - When array is reverse sorted

Space Complexity: O(1) - In-place algorithm

Characteristics:
- Simple implementation
- Stable sorting algorithm
- In-place algorithm
- Efficient for small data sets
- More efficient than bubble/selection sort
- Adaptive - becomes faster when array is partially sorted
- Online - can sort a list as it receives it
*/
/*
             Timestamp  : 11:15 - Monday  31,Mar 2025
*/
#include <bits/stdc++.h>
using namespace std;

void Insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Insertion Sort
    Insertion_sort(arr, n);

    return 0;
}