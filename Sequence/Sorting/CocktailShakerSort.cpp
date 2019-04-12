#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void cocktailShakerSort(int arr[], int n) {
  bool swapped;
  do {
    swapped = false;
    for (int i = 0; i < n-1; i++) {
      if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
    swapped = false;
    for (int i = n-2; i >= 0; i--) {
      if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
        swapped = true;
      }
    }
  } while (swapped);
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
  cocktailShakerSort(arr, n);
}
