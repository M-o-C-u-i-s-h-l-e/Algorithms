#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void simpleMerge(int a1[], int a2[], int n, int m) {
  int arr[n+m];
  int i = 0, j = 0, k = 0;
  while (i < n && j < m) {
    if (a1[i] <= a2[j]) {
      arr[k] = a1[i];
      i++;
    } else {
      arr[k] = a2[j];
      j++;
    }
    k++;
  }
  while (i < n) {
    arr[k] = a1[i];
    i++, k++;
  }
  while (j < m) {
    arr[k] = a2[j];
    j++, k++;
  }
  print(arr, n+m);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  int a1[n], a2[m];
  for (int i = 0; i < n; i++) cin >> a1[i];
  for (int i = 0; i < m; i++) cin >> a2[i];
  simpleMerge(a1, a2, n, m);
}
