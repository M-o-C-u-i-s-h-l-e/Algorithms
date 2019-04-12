#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void flip(int arr[], int i) {
  int start = 0;
  while (start < i) {
    swap(arr[start], arr[i]);
    start++, i--;
  }
}

int findMax(int arr[], int n) {
  int maxIndex = 0;
  for (int i = 0; i < n; i++)
    if (arr[i] > arr[maxIndex])
      maxIndex = i;
  return maxIndex;
}

void pancakeSort(int arr[], int n) {
  for (int curSize = n; curSize > 1; curSize--) {
    int maxIndex = findMax(arr, curSize);
    if (maxIndex != curSize - 1) {
      flip(arr, maxIndex);
      flip(arr, curSize - 1);
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
  pancakeSort(arr, n);
}
