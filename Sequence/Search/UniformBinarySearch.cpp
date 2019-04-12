#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define log_n 42

int delta[log_n];

void make_delta(int n) {
  int power = 1;
  int i = 0;
  do {
    int half = power;
    power <<= 1;
    delta[i] = (n + half) / power;
  } while (delta[i++] != 0);
}

int uniSearch(int arr[], int key) {
  int i = delta[0] - 1, d = 0;
  while (true) {
    if (key == arr[i])  return i;
    else if (delta[d] == 0) return -1;
    else
      (key < arr[i]) ? i -= delta[++d] : i += delta[++d];
  }
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
  make_delta(n);
  cout << uniSearch(arr, key) << endl;
}
