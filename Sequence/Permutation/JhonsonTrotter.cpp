#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int searchArr(int arr[], int n, int mobile) {
  for (int i = 0; i < n; i++)
    if (arr[i] == mobile)
      return i + 1;
}

int getMobile(int arr[], bool dir[], int n) {
  int mobile_prev = 0, mobile = 0;
  for (int i = 0; i < n; i++) {
    if (!dir[arr[i]-1] && i != 0) {
      if (arr[i] > arr[i-1] && arr[i] > mobile_prev) {
        mobile = arr[i];
        mobile_prev = mobile;
      }
    }
    if (dir[arr[i]-1] && i != n-1) {
      if (arr[i] > arr[i+1] && arr[i] > mobile_prev) {
        mobile = arr[i];
        mobile_prev = mobile;
      }
    }
  }
  return (mobile == 0 && mobile_prev == 0) ? 0 : mobile;
}

int printOnePermutation(int arr[], bool dir[], int n) {
  int mobile = getMobile(arr, dir, n);
  int pos = searchArr(arr, n, mobile);
  if (!dir[arr[pos-1]-1])
    swap(arr[pos-1], arr[pos-2]);
  else if (dir[arr[pos-1]-1])
    swap(arr[pos], arr[pos-1]);
  for (int i = 0; i < n; i++) {
    if (arr[i] > mobile) {
      if (dir[arr[i]-1])  dir[arr[i]-1] = false;
      else if (!dir[arr[i]-1])  dir[arr[i]-1] = true;
    }
  }
  for (int i = 0; i < n; i++)
    cout << arr[i];
  cout << endl;
}

int fact(int n) {
  int pro = 1;
  for (int i = 1; i <= n; i++)
    pro *= i;
  return pro;
}

void Permutation(int n) {
  int arr[n];
  bool dir[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
    cout << arr[i];
  }
  cout << endl;
  memset(dir, false, sizeof(dir));
  for (int i = 1, f = fact(n); i < f; i++)
    printOnePermutation(arr, dir, n);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  Permutation(n);
}
