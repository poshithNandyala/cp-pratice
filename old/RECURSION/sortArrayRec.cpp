#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &arr, int last) {
  if (arr.size() == 0 || arr.back() <= last) {
    arr.push_back(last);
    return;
  }
  int temp = arr.back();
  arr.pop_back();
  insert(arr, last);
  arr.push_back(temp);
}
void sortArrayRec(vector<int> &arr) {
  if (arr.size() == 0) {
    return;
  }
  int last = arr.back();
  arr.pop_back();
  sortArrayRec(arr);
  insert(arr, last);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sortArrayRec(arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
