#include<bits/stdc++.h>
using namespace std;

vector<int> findsmallestlargest(vector<int>& arr) {
    int smallest = INT_MAX, largest = INT_MIN;
    int second_smallest = INT_MAX, second_largest = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < second_smallest) {
            second_smallest = arr[i];
        }
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest) {
            second_largest = arr[i];
        }
    }


    return { second_smallest, second_largest };
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> b = findsmallestlargest(arr);
    cout << b[0] << " " << b[1] << endl;
}
