#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int arr[], int l, int r) {
  int i = l - 1, x = arr[r];
  for (int j = l; j < r; j++) {
    if (arr[j] <= x) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i + 1;
}

void quickSort(int arr[], int l, int r) {
  if (l < r) {
    int m = partition(arr, l, r);
    quickSort(arr, l, m-1);
    quickSort(arr, m+1, r);
  }
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
  quickSort(arr, 0, n-1);
  print(arr, n);
}
