#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int arr[], int n) {
  int i, j, min_index;
  for (i = 0; i < n-1; i++) {
    min_index = i;
    for (j = i+1; j < n; j++)
      if (arr[j] < arr[min_index])
        min_index = j;
    swap(&arr[min_index], &arr[i]);
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
  selectionSort(arr, n);
}
