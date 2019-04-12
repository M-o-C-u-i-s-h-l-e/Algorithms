#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void cycleSort(int arr[], int n) {
  for (int cycleStart = 0; cycleStart < n-1; cycleStart++) {
    int item = arr[cycleStart];
    int pos = cycleStart;
    for (int i = cycleStart+1; i < n; i++)
      if (arr[i] < item)
        pos++;
    if (pos == cycleStart)
      continue;
    while (item == arr[pos])
      pos += 1;
    if (pos != cycleStart)
      swap(item, arr[pos]);
    while (pos != cycleStart) {
      pos = cycleStart;
      for (int i = cycleStart+1; i < n; i++)
        if (arr[i] < item)
          pos += 1;
      while (item == arr[pos])
        pos += 1;
      if (item != arr[pos])
        swap(item, arr[pos]);
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
  cycleSort(arr, n);
}
