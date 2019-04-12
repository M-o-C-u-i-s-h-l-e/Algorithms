#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int jumpSearch(int arr[], int n, int key) {
  int a = 0, b = sqrt(n);
  while (arr[min(b, n) - 1] < key) {
    a = b;
    b += sqrt(n);
    if (a >= n) return -1;
  }
  while (arr[a] < key) {
    a++;
    if (a == min(b, n)) return -1;
  }
  return (arr[a] == key) ? a : -1;
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
  cout << jumpSearch(arr, n, key) << endl;
}
