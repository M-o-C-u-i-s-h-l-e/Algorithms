#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int ternarySearch(int arr[], int l, int r, int key) {
  if (l <= r) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    if (arr[mid1] == key) return mid1;
    if (arr[mid2] == key) return mid2;
    if (key < arr[mid1])
      return ternarySearch(arr, l, mid1-1, key);
    else if (key > arr[mid2])
      return ternarySearch(arr, mid2+1, r, key);
    return ternarySearch(arr, mid1+1, mid2-1, key);
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
  cout << ternarySearch(arr, 0, n-1, key) << endl;
}
