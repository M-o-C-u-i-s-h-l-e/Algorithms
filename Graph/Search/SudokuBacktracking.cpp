#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define N 9

void print(int grid[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << grid[i][j] << " ";
    cout << endl;
  }
}

bool findEmpty(int grid[N][N], int &row, int &col) {
  for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
      if (grid[row][col] == 0)
        return true;
  return false;
}

bool usedInRow(int grid[N][N], int row, int num) {
  for (int col = 0; col < N; col++)
    if (grid[row][col] == num)
      return true;
  return false;
}

bool usedInCol(int grid[N][N], int col, int num) {
  for (int row; row < N; row++)
    if (grid[row][col] == num)
      return true;
  return false;
}

bool usedInBox(int grid[N][N], int Startrow, int Startcol, int num) {
  for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
      if (grid[row + Startrow][col + Startcol] == num)
        return true;
  return false;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
  return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) &&
    !usedInBox(grid, row - row%3, col - col%3, num) && grid[row][col] == 0;
}

bool sudoku(int grid[N][N]) {
  int row, col;
  if (!findEmpty(grid, row, col))
    return true;
  for (int num = 1; num <= 9; num++) {
    if (isSafe(grid, row, col, num)) {
      grid[row][col] = num;
      if (sudoku(grid))
        return true;
      grid[row][col] = 0;
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int grid[N][N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> grid[i][j];
  if (sudoku(grid))
    print(grid);
  else
    cout << "No Solution Exists\n";
}
