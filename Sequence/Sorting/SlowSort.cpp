#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void slowSort(int arr[], int i, int j) {
  if (i >= j) return;
  int m = (i + j) / 2;
  slowSort(arr, i, m);
  slowSort(arr, m+1, j);
  if (arr[j] < arr[m])
    swap(arr[j], arr[m]);
  slowSort(arr, i, j-1);
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
  slowSort(arr, 0, n-1);
  print(arr, n);
}
