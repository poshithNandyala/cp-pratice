/*
/*
selection sort

what do u select -> we select minimum

first we select minimum element and swap it with first element
then we select minimum element from remaining array and swap it with second element
and so on



algorithm:

swap 0 and minumum element
swap 1 and minimum element from remaining array
swap 2 and minimum element from remaining array excluding first two elements
and so on till n-1



Selection Sort Algorithm

Selection Sort is a simple comparison-based sorting algorithm that works by repeatedly finding
the minimum element from the unsorted portion and placing it at the beginning.

Algorithm:
1. Start with the entire array as unsorted
2. For each position i from 0 to n-1:
   - Find minimum element in unsorted subarray [i..n-1]
   - Swap this minimum with element at position i
   - Portion [0..i] becomes sorted

Example:
Initial array: [64, 25, 12, 22, 11]
Pass 1: [11, 25, 12, 22, 64] - Found min 11, swapped with 64
Pass 2: [11, 12, 25, 22, 64] - Found min 12, swapped with 25
Pass 3: [11, 12, 22, 25, 64] - Found min 22, swapped with 25
Pass 4: [11, 12, 22, 25, 64] - Found min 25, no swap needed

Time Complexity:
- Best Case: O(n²)
- Average Case: O(n²)
- Worst Case: O(n²)

Space Complexity: O(1) - In-place algorithm

Characteristics:
- Simple implementation
- In-place sorting
- Not stable
- Efficient for small arrays
- Performs poorly on large datasets compared to advanced algorithms
*/
/*
             Timestamp  : 10:57 - Monday  31,Mar 2025   
*/
#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selection_sort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}