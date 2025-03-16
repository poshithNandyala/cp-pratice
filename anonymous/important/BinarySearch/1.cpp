#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int lower_bound(int arr[], int n, int key)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if (arr[l] >= key)
    {
        return l;
    }
    else if (arr[r] >= key)
    {
        return r;
    }
    else
    {
        return -1;
    }
}

int upper_bound(int arr[], int n, int key)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if (arr[l] > key)
    {
        return l;
    }
    else if (arr[r] > key)
    {
        return r;
    }
    else
    {
        return -1;
    }
    
}
int main()
{
    fastio;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if (arr[l] == key)
    {
        cout << "Found at left " << l << endl;
    }
    else if (arr[r] == key)
    {
        cout << "Found at  right" << r << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    cout<< endl;
    cout << "Lower Bound: " << lower_bound(arr, n, key)<<" "<<arr[lower_bound(arr, n, key)] << endl;
    cout << endl;
    cout << "Upper Bound: " << upper_bound(arr, n, key) <<" "<<arr[upper_bound(arr, n, key)] << endl;
}