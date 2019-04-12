#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int ceilIndex(int arr[], int l, int r, int key) {
  while (r - l > 1) {
    int m = (l + r) / 2;
    (arr[m] >= key) ? r = m : l = m;
  }
  return r;
}

int longestIncreasingSubsequence(int arr[], int n) {
  if (n == 0)
    return 0;
  int tail[n], length = 1;
  for (int i = 0; i < n; i++) tail[i] = 0;
  tail[0] = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < tail[0])
      tail[0] = arr[i];
    else if (arr[i] > tail[length-1])
      tail[length++] = arr[i];
    else
      tail[ceilIndex(tail, -1, length-1, arr[i])] = arr[i];
  }
  return length;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << longestIncreasingSubsequence(arr, n) << endl;
}
