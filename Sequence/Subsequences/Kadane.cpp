#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int maxSubArray(int arr[], int n) {
  int maxSoFar = INT_MIN, maxEndingHere = 0;
  for (int i = 0; i < n; i++) {
    maxEndingHere += arr[i];
    if (maxSoFar < maxEndingHere)
      maxSoFar = maxEndingHere;
    if (maxEndingHere < 0)
      maxEndingHere = 0;
  }
  return maxSoFar;
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
  cout << maxSubArray(arr, n) << endl;
}
