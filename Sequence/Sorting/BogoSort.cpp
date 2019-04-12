#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

bool isSorted(int arr[], int n) {
  for (int i = 0; i < n-1; i++)
    if (arr[i] > arr[i+1])
      return false;
  return true;
}

void shuffle(int arr[], int n) {
  for (int i = 0; i < n; i++)
    swap(arr[i], arr[rand()%n]);
}

void bogoSort(int arr[], int n) {
  while (!isSorted(arr, n))
    shuffle(arr, n);
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
  bogoSort(arr, n);
}
