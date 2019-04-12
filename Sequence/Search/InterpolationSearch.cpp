#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int interpolationSearch(int arr[], int n, int key) {
  int start = 0, end = n - 1;
  while (start <= end && key >= arr[start] && key <= arr[end]) {
    if (start == end) {
      if (arr[start] == key)  return start;
      return -1;
    }
    int pos = start + (((double)(end - start) / (arr[end] - arr[start])) * (key - arr[start]));
    if (arr[pos] == key)  return pos;
    if (arr[pos] < key) start = pos + 1;
    else  end = pos - 1;
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
  cout << interpolationSearch(arr, n, key) << endl;
}
