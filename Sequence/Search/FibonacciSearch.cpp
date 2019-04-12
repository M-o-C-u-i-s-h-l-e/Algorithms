#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int fibonacciSearch(int arr[], int n, int key) {
  int fib2 = 0, fib1 = 1;
  int fib = fib2 + fib1;
  while (fib < n) {
    fib2 = fib1;
    fib1 = fib;
    fib = fib2 + fib1;
  }
  int offSet = -1;
  while (fib > 1) {
    int i = min(offSet + fib2, n - 1);
    if (arr[i] < key) {
      fib = fib1;
      fib1 = fib2;
      fib2 = fib - fib1;
      offSet = i;
    } else if (arr[i] > key) {
      fib = fib2;
      fib1 = fib1 - fib2;
      fib2 = fib - fib1;
    } else {
      return i;
    }
  }
  if (fib1 && arr[offSet+1] == key) return offSet + 1;
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
  cout << fibonacciSearch(arr, n, key) << endl;
}
