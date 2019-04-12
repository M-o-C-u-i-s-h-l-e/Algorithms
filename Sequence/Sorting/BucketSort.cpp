#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(float arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void bucketSort(float arr[], int n) {
  vector<float> b[n];
  for (int i = 0; i < n; i++) {
    int bi = n * arr[i];
    b[bi].push_back(arr[i]);
  }
  for (int i = 0; i < n; i++)
    sort(b[i].begin(), b[i].end());
  int index = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < b[i].size(); j++)
      arr[index++] = b[i][j];
  print(arr, n);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  float arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  bucketSort(arr, n);
}
