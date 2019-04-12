#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void heapPermutation(int arr[], int size, int n) {
  if (size == 1) {
    print(arr, n);
    return;
  }
  for (int i = 0; i < size; i++) {
    heapPermutation(arr, size-1, n);
    (size%2 == 1) ? swap(arr[0], arr[size-1]) : swap(arr[i], arr[size-1]);
  }
}

/*
// Iterative Version
void heapPermutation(int arr[], int n) {
  int c[n];
  for (int i = 0; i < n; i++) c[i] = 0;
  print(arr, n);
  int i = 0;
  while (i < n) {
    if (c[i] < i) {
      (i%2 == 0) ? swap(arr[0], arr[i]) : swap(arr[c[i]], arr[i]);
      print(arr, n);
      c[i]++, i = 0;
    } else {
      c[i] = 0, i++;
    }
  }
}
*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  heapPermutation(arr, n, n);
}
