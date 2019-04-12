#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void insertionSort(int arr[], int n) {
  int i = 1;
  while (i < n) {
    int j = i;
    while (j > 0 && arr[j-1] > arr[j]) {
      swap(arr[j], arr[j-1]);
      j--;
    }
    i++;
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
  insertionSort(arr, n);
}
