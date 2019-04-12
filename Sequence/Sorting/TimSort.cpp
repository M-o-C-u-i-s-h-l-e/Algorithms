#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void insertionSort(int arr[], int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int temp = arr[i];
    int j = i - 1;
    while (arr[j] > temp && j >= left) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}

void merge(int arr[], int l, int m, int r) {
  int len1 = m - l + 1, len2 = r - m;
  int left[len1], right[len2];
  for (int i = 0; i < len1; i++)
    left[i] = arr[l+i];
  for (int i = 0; i < len2; i++)
    right[i] = arr[m+1+i];
  int i = 0, j = 0, k = l;
  while (i < len1 && j < len2)
    (left[i] <= right[j]) ? arr[k++] = left[i++] : arr[k++] = right[j++];
  while (i < len1)
    arr[k++] = left[i++];
  while (j < len2)
    arr[k++] = right[j++];
}

void timSort(int arr[], int n) {
  for (int i = 0; i < n; i+=32)
    insertionSort(arr, i, min(i+31, n-1));
  for (int size = 32; size < n; size *= 2) {
    for (int left = 0; left < n; left += 2*size) {
      int mid = left + size - 1;
      int right = min((left + 2*size - 1), (n - 1));
      merge(arr, left, mid, right);
    }
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
  timSort(arr, n);
  print(arr, n);
}
