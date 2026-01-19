/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

pushing largest element to the end
then pushing second largest element to second last position
and finally smallest element to first position by adjacent swaps

Steps:

1. Start from the first element and compare each pair of adjacent elements
2. If the first element is greater than second element, swap them
3. Move to next pair of adjacent elements and repeat step 2
4. After first pass, largest element will be at the end
5. Repeat steps 1-4 for remaining n-1 elements
6. Continue until no more swaps are needed

Example:
Initial array: [64, 34, 25, 12, 22, 11, 90]
Pass 1: [34, 25, 12, 22, 11, 64, 90] - 90 bubbles to end
Pass 2: [25, 12, 22, 11, 34, 64, 90] - 64 bubbles to second last
Pass 3: [12, 22, 11, 25, 34, 64, 90] - And so on...

Time Complexity:
- Best Case: O(n) - When array is already sorted
- Average Case: O(n^2)
- Worst Case: O(n^2) - When array is reverse sorted

Space Complexity: O(1) - In-place algorithm

Characteristics:
- Simple implementation
- Stable sorting algorithm
- In-place algorithm - no extra space needed
- Not suitable for large datasets
- Adaptive - becomes faster when array is partially sorted
*/
/*
             Timestamp  : 11:04 - Monday  31,Mar 2025
*/
#include <bits/stdc++.h>
using namespace std;

void Bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
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
        cin >> arr[i];

    Bubble_sort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}