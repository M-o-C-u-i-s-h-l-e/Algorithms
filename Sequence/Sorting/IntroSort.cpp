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

void insertionSort(int arr[], int *begin, int *end) {
  int left = begin - arr;
  int right = end - arr;
  for (int i = left + 1; i <= right; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= left && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

int *partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
    if (arr[j] <= pivot)
      swap(arr[++i], arr[j]);
  swap(arr[i+1], arr[high]);
  return arr + i + 1;
}

int *medianOfThree(int *a, int *b, int *c) {
  if ((*b <= *a && *a < *c) || (*c <= *a && *a < *b))
    return a;
  if ((*a < *b && *b < *c) || (*c <= *b && *b <= *c))
    return b;
  if ((*a < *c && *c <= *b) || (*b < *c && *c <= *a))
    return c;
}

void introSortUtil(int arr[], int *begin, int *end, int depthLimit) {
  int size = end - begin;
  if (size < 16) {
    insertionSort(arr, begin, end);
    return;
  }
  if (depthLimit == 0) {
    make_heap(begin, end+1);
    sort_heap(begin, end+1);
    return;
  }
  int *pivot = medianOfThree(begin, begin + size / 2, end);
  swap(pivot, end);
  int *partitionPoint = partition(arr, begin-arr, end-arr);
  introSortUtil(arr, begin, partitionPoint-1, depthLimit-1);
  introSortUtil(arr, partitionPoint+1, end, depthLimit-1);
}

void introSort(int arr[], int *begin, int *end) {
  int depthLimit = 2 * log(end - begin);
  introSortUtil(arr, begin, end, depthLimit);
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
  introSort(arr, arr, arr+n-1);
  print(arr, n);
}
