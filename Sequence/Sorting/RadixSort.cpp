#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int getMax(int arr[], int n) {
  int Max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > Max)
      Max = arr[i];
  return Max;
}

void countSort(int arr[], int n, int exp) {
  int output[n];
  int i, count[10] = {0};
  for (i = 0; i < n; i++)
    count[(arr[i]/exp)%10]++;
  for (i = 1; i < 10; i++)
    count[i] += count[i-1];
  for (i = n - 1; i >= 0; i--) {
    output[count[(arr[i]/exp)%10] - 1] = arr[i];
    count[(arr[i]/exp)%10]--;
  }
  for (i = 0; i < n; i++)
    arr[i] = output[i];
}

void radixSort(int arr[], int n) {
  int Max = getMax(arr, n);
  for (int exp = 1; Max/exp > 0; exp *= 10)
    countSort(arr, n, exp);
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
  radixSort(arr, n);
}
