
#include <iostream>
using namespace std;

// int maxSubArraySum(int arr[], int size) {
//     int maxSoFar = arr[0];
//     int currMax = arr[0];
    
//     for (int i = 1; i < size; i++) {
//         currMax = max(arr[i], currMax + arr[i]);
//         maxSoFar = max(maxSoFar, currMax);
//     }
//     return maxSoFar;
// }

int maxSubArraySum(int arr[], int size)
{
    int maxSoFar = arr[0];
    int currMax = arr[0];

    for (int i = 1; i < size; i++)
    {
        // if currMax + arr[i] is negative, set to 0 instead of using max
        currMax = currMax + arr[i];
        if (currMax < 0)
        {
            currMax = 0;
        }
        if (currMax > maxSoFar)
        {
            maxSoFar = currMax;
        }
    }
    return maxSoFar;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int maxSum = maxSubArraySum(arr, n);
    cout << "Maximum contiguous sum is " << maxSum << endl;
    
    return 0;
}
