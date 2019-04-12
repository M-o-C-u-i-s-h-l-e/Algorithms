#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define N 8

int cx[N] = {1, 1, 2, 2, -1, -1, -2, -2};
int cy[N] = {2, -2, 1, -1, 2, -2, 1, -1};

bool limits(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < N) && (y < N);
}

bool isempty(int a[], int x, int y) {
  return (limits(x, y) && (a[y*N + x] < 0));
}

int getDegree(int a[], int x, int y) {
  int Count = 0;
  for (int i = 0; i < N; i++)
    if (isempty(a, (x + cx[i]), (y + cy[i])))
      Count++;
  return Count;
}

bool nextMove(int a[], int *x, int *y) {
  int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;
  int start = rand() % N;
  for (int Count = 0; Count < N; Count++) {
    int i = (start + Count) % N;
    nx = *x + cx[i];
    ny = *y + cy[i];
    if (isempty(a, nx, ny) && (c = getDegree(a, nx, ny)) < min_deg) {
      min_deg_idx = i;
      min_deg = c;
    }
  }
  if (min_deg_idx == -1)
    return false;
  nx = *x + cx[min_deg_idx];
  ny = *y + cy[min_deg_idx];
  a[ny*N + nx] = a[(*y)*N + (*x)] + 1;
  *x = nx;
  *y = ny;
  return true;
}

void print(int a[]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << a[j*N + i] << " ";
    cout << endl;
  }
}

bool neighbour(int x, int y, int xx, int yy) {
  for (int i = 0; i < N; i++)
    if ((x + cx[i] == xx) && (y + cy[i] == yy))
      return true;
  return false;
}

bool findClosedTour() {
  int a[N*N];
  for (int i = 0; i < N*N; i++)
    a[i] = -1;
  int sx = rand() % N;
  int sy = rand() % N;
  int x = sx, y = sy;
  a[y*N + x] = 1;
  for (int i = 0; i < N*N - 1; i++)
    if (!nextMove(a, &x, &y))
      return false;
  if (!neighbour(x, y, sx, sy))
    return false;
  print(a);
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  srand(time(NULL));
  while (!findClosedTour()) {
    ;
  }
}
