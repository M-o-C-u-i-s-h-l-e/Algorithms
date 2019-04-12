#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void beadSort(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  unsigned char beads[max * n];
  memset(beads, 0, sizeof(beads));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < arr[i]; j++)
      beads[i*max + j] = 1;
  for (int j = 0; j < max; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += beads[i*max + j];
      beads[i*max + j] = 0;
    }
    for (int i = n-sum; i < n; i++)
      beads[i*max + j] = 1;
  }
  for (int i = 0; i < n; i++) {
    int j;
    for (j = 0; j < max && beads[i*max + j]; j++);
    arr[i] = j;
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
  beadSort(arr, n);
}
