#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void oddEvenSort(int arr[], int n) {
  bool sorted = false;
  while (!sorted) {
    sorted = true;
    for (int i = 1; i < n-1; i+=2) {
      if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
        sorted = false;
      }
    }
    for (int i = 0; i < n-1; i+=2) {
      if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
        sorted = false;
      }
    }
  }
  print(arr, n);
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
  oddEvenSort(arr, n);
}
