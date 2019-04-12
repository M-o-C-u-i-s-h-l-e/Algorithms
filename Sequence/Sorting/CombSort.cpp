#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void combSort(int arr[], int n) {
  int gap = n;
  float shrink = 1.3;
  bool sorted = false;
  while (!sorted) {
    gap = floor(gap / shrink);
    if (gap <= 1) {
      gap = 1;
      sorted = true;
    }
    int i = 0;
    while (i+gap < n) {
      if (arr[i] > arr[i+gap]) {
        swap(arr[i], arr[i+gap]);
        sorted = false;
      }
      i++;
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
  combSort(arr, n);
}
