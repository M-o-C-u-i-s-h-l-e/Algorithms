#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int binarySearch(int arr[], int l, int r, int key) {
  if (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == key)  return mid;
    else if (arr[mid] > key)
      return binarySearch(arr, l, mid-1, key);
    return binarySearch(arr, mid+1, r, key);
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int key;
  cin >> key;
  cout << binarySearch(arr, 0, n-1, key) << endl;
}
