#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int linearSearch(int arr[], int n, int key) {
  for (int i = 0; i < n; i++)
    if (arr[i] == key)
      return i;
  return -1;
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
  int key;
  cin >> key;
  cout << linearSearch(arr, n, key) << endl;
}
