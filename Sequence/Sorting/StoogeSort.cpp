#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void stoogeSort(int arr[], int i, int j) {
  if (arr[i] > arr[j])
    swap(arr[i], arr[j]);
  if (j-i+1 > 2) {
    int m = (j - i + 1) / 3;
    stoogeSort(arr, i, j-m);
    stoogeSort(arr, i+m, j);
    stoogeSort(arr, i, j-m);
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
  stoogeSort(arr, 0, n-1);
  print(arr, n);
}
