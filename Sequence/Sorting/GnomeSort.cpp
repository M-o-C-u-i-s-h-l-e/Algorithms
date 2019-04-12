#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void gnomeSort(int arr[], int n) {
  int i = 0;
  while (i < n) {
    if (i == 0) i++;
    if (arr[i] >= arr[i-1]) {
      i++;
    } else {
      swap(arr[i], arr[i-1]);
      i--;
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
  gnomeSort(arr, n);
}
