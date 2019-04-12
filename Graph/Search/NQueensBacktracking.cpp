#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, Count = 0;

void print(vector<bool> board[]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

bool isSafe(vector<bool> board[], int row, int col) {
  int i, j;
  for (i = 0; i < col; i++)
    if (board[row][i])
      return false;
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return false;
  for (i = row, j = col; i < n && j >= 0; i++, j--)
    if (board[i][j])
      return false;
  return true;
}

bool nQueens(vector<bool> board[], int col) {
  if (col >= n)
    return true;
  for (int i = 0; i < n; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;
      if (nQueens(board, col+1))
        return true;
        board[i][col] = 0;
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  vector<bool> board[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      board[i].push_back(false);
  if (!nQueens(board, 0))
    cout << "Solution does not exits\n";
  else
    print(board);
}
