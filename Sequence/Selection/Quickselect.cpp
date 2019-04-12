#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int partition(int arr[], int l, int r) {
  int x = arr[r], i = l;
  for (int j = l; j < r; j++) {
    if (arr[j] <= x) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[r]);
  return i;
}

int kthSmallest(int arr[], int l, int r, int k) {
  if (k > 0 && k <= r - l + 1) {
    int index = partition(arr, l, r);
    if (index - l + 1 == k)
      return arr[index];
    if (index - l + 1 > k)
      return kthSmallest(arr, l, index - 1, k);
    return kthSmallest(arr, index + 1, r, k - index + l - 1);
  }
  return INT_MAX;
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
  int k;
  cin >> k;
  cout << kthSmallest(arr, 0, n-1, k) << endl;
}
