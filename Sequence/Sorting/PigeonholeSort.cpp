#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void pigeonholeSort(int arr[], int n) {
  int min = arr[0], max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) min = arr[i];
    if (arr[i] > max) max = arr[i];
  }
  int range = max - min + 1;
  vector<int> holes[range];
  for (int i = 0; i < n; i++)
    holes[arr[i] - min].push_back(arr[i]);
  int index = 0;
  for (int i = 0; i < range; i++)
    for (auto itr = holes[i].begin(); itr != holes[i].end(); itr++)
      arr[index++] = *itr;
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
  pigeonholeSort(arr, n);
}
