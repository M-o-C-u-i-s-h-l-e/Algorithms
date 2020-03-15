// Time Complexity - O(E)   (i.e., in worst case)

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define pdpii pair<double, pair<int, int>>

class node {
public:
	int parent_i, parent_j;
	double f, g, h;
};

int row, col;
pii src, dest;
vector<vector<int>> grid;
vector<vector<node>> nodeDetails;
vector<vector<bool>> closedList;
bool foundDest = false;

bool isValid(int r, int c) {
	return (r >= 0 && r < row) && (c >= 0 && c < col);
}

bool isUnblocked(int r, int c) {
	return grid[r][c] == 1 ? true : false;
}

bool isDestination(int r, int c) {
	return (r == dest.first && c == dest.second) ? true : false;
}

bool calculateHValue(int r, int c) {
	return (double)(sqrt(pow(r - dest.first, 2) + pow(c - dest.second, 2)));
}

void tracePath() {
	cout << "The Path is: \n";
	int r = dest.first, c = dest.second;
	stack<pii> path;
	while (!(nodeDetails[r][c].parent_i == r && nodeDetails[r][c].parent_j == c)) {
		path.push({r, c});
		int tempR = nodeDetails[r][c].parent_i;
		int tempC = nodeDetails[r][c].parent_j;
		r = tempR, c = tempC;
	}
	path.push({r, c});
	while (!path.empty()) {
		pii p = path.top();
		path.pop();
		cout << p.first << " " << p.second << endl;
	}
}

void move(int curR, int curC, int nextR, int nextC, set<pdpii> &openList, bool straight) {
	if (isValid(nextR, nextC)) {
		if (isDestination(nextR, nextC)) {
			nodeDetails[nextR][nextC].parent_i = curR;
			nodeDetails[nextR][nextC].parent_j = curC;
			cout << "\nThe Destination node is Found" << endl;
			tracePath();
			foundDest = true;
			return;
		} else if (!closedList[nextR][nextC] && isUnblocked(nextR, nextC)) {
			double gNew = nodeDetails[curR][curC].g + (straight ? 1.0 : 1.414);
			double hNew = calculateHValue(nextR, nextC);
			double fNew = gNew + hNew;
			if (nodeDetails[nextR][nextC].f == FLT_MAX || nodeDetails[nextR][nextC].f > fNew) {
				openList.insert({fNew, {nextR, nextC}});
				nodeDetails[nextR][nextC].f = fNew;
				nodeDetails[nextR][nextC].g = gNew;
				nodeDetails[nextR][nextC].h = hNew;
				nodeDetails[nextR][nextC].parent_i = curR;
				nodeDetails[nextR][nextC].parent_j = curC;
			}
		}
	}
}

void aStarSearch() {
	if (!isValid(src.first, src.second) || !isValid(dest.first, dest.second)) {
		cout << "Source or Destination is Invalid" << endl;
		return;
	}
	if (!isUnblocked(src.first, src.second) || !isUnblocked(dest.first, dest.second)) {
		cout << "Source or Destination is blocked" << endl;
		return;
	}
	if (isDestination(src.first, src.second)) {
		cout << "We are already at the Destination" << endl;
		return;
	}

	closedList.resize(row, vector<bool>(col, false));
	nodeDetails.resize(row, vector<node>(col));
	int i, j;
	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			nodeDetails[i][j].f = FLT_MAX;
			nodeDetails[i][j].g = FLT_MAX;
			nodeDetails[i][j].h = FLT_MAX;
			nodeDetails[i][j].parent_i = -1;
			nodeDetails[i][j].parent_j = -1;
		}
	}
	i = src.first, j = src.second;
	nodeDetails[i][j].f = 0;
	nodeDetails[i][j].g = 0;
	nodeDetails[i][j].h = 0;
	nodeDetails[i][j].parent_i = i;
	nodeDetails[i][j].parent_j = j;
	set<pdpii> openList;
	openList.insert({0, {i, j}});
	while (!openList.empty()) {
		pdpii p = *openList.begin();
		openList.erase(openList.begin());
		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;
		move(i, j, i - 1, j, openList, true);			// North
		if (foundDest)	return;
		move(i, j, i + 1, j, openList, true);			// South
		if (foundDest)	return;
		move(i, j, i, j + 1, openList, true);			// East
		if (foundDest)	return;
		move(i, j, i, j - 1, openList, true);			// West
		if (foundDest)	return;
		move(i, j, i - 1, j + 1, openList, false);		// North-East
		if (foundDest)	return;
		move(i, j, i - 1, j - 1, openList, false);		// North-West
		if (foundDest)	return;
		move(i, j, i + 1, j + 1, openList, false);		// South-East
		if (foundDest)	return;
		move(i, j, i + 1, j - 1, openList, false);		// South-West
		if (foundDest)	return;
	}
	if (!foundDest)
		cout << "Failed to find Destination node" << endl;
}

int main(void) {
	cout << "Enter Row size: ";
	cin >> row;
	cout << "Enter Column size: ";
	cin >> col;
	grid.resize(row, vector<int>(col));
	cout << "Enter The Matrix:\n";
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> grid[i][j];
	cout << "Enter Source point: ";
	cin >> src.first >> src.second;
	cout << "Enter Destination point: ";
	cin >> dest.first >> dest.second;
	aStarSearch();
}







#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>
#define pdpii pair<double, pair<int, int>>

vector<vector<int>> grid;
int ROW, COL;

class cell {
public:
  int parent_i, parent_j;
  double f, g, h;
};

bool isValid(int row, int col) {
  return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool isUnBlocked(int row, int col) {
  return (grid[row][col] == 1) ? true : false;
}

bool isDestination(int row, int col, pii dest) {
  return (row == dest.first && col == dest.second) ? true : false;
}

double calHValue(int row, int col, pii dest) {
  return ((double) sqrt(pow(row-dest.first, 2) + pow(col-dest.second, 2)));
}

void tracePath(vector<vector<cell>> cellDetails, pii dest) {
  cout << "The Path is: ";
  int row = dest.first;
  int col = dest.second;
  stack<pii> Path;
  while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
    Path.push(make_pair(row, col));
    int temp_row = cellDetails[row][col].parent_i;
    int temp_col = cellDetails[row][col].parent_j;
    row = temp_row;
    col = temp_col;
  }
  Path.push(make_pair(row, col));
  while (!Path.empty()) {
    pair<int,int> p = Path.top();
    Path.pop();
    cout << "-> (" << p.first << "," << p.second << ")";
  }
  cout << endl;
}

void aStarSearch(pii src, pii dest) {
  if (isValid (src.first, src.second) == false) {
    cout << "Source is invalid\n";
    return;
  }
  if (isValid (dest.first, dest.second) == false) {
    cout << "Destination is invalid\n";
    return;
  }
  if (!isUnBlocked(src.first, src.second) || !isUnBlocked(dest.first, dest.second)) {
    cout << "Source or the destination is blocked\n";
    return;
  }
  if (isDestination(src.first, src.second, dest)) {
    cout << "We are already at the destination\n";
    return;
  }
  bool closedList[ROW][COL];
  memset(closedList, false, sizeof(closedList));
  vector<vector<cell>> cellDetails;
  int i, j;
  for (i = 0; i < ROW; i++) {
    vector<cell> v(COL);
    for (j = 0; j < COL; j++) {
      v[j].f = FLT_MAX;
      v[j].g = FLT_MAX;
      v[j].h = FLT_MAX;
      v[j].parent_i = -1;
      v[j].parent_j = -1;
    }
    cellDetails.push_back(v);
  }
  i = src.first, j = src.second;
  cellDetails[i][j].f = 0.0;
  cellDetails[i][j].g = 0.0;
  cellDetails[i][j].h = 0.0;
  cellDetails[i][j].parent_i = i;
  cellDetails[i][j].parent_j = j;
  set<pdpii> openList;
  openList.insert(make_pair(0.0, make_pair(i, j)));
  bool foundDest = false;

  while (!openList.empty()) {
    pdpii p = *openList.begin();
    openList.erase(openList.begin());
    i = p.second.first;
    j = p.second.second;
    closedList[i][j] = true;
    double gNew, hNew, fNew;
    if (isValid(i-1, j)) {
      if (isDestination(i-1, j, dest)) {
        cellDetails[i-1][j].parent_i = i;
        cellDetails[i-1][j].parent_j = j;
        cout << "The Destination is found\n";
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
      } else if (!closedList[i-1][j] && isUnBlocked(i-1, j)) {
        gNew = cellDetails[i][j].g + 1.0;
        hNew = calHValue(i-1, j, dest);
        fNew = gNew + hNew;
        if (cellDetails[i-1][j].f == FLT_MAX || cellDetails[i-1][j].f > fNew) {
          openList.insert(make_pair(fNew, make_pair(i-1, j)));
          cellDetails[i-1][j].f = fNew;
          cellDetails[i-1][j].g = gNew;
          cellDetails[i-1][j].h = hNew;
          cellDetails[i-1][j].parent_i = i;
          cellDetails[i-1][j].parent_j = j;
        }
      }
    }
    if (isValid(i+1, j)) {
      if (isDestination(i+1, j, dest)) {
        cellDetails[i+1][j].parent_i = i;
        cellDetails[i+1][j].parent_j = j;
        cout << "The Destination is found\n";
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
      } else if (!closedList[i+1][j] && isUnBlocked(i+1, j)) {
        gNew = cellDetails[i][j].g + 1.0;
        hNew = calHValue(i+1, j, dest);
        fNew = gNew + hNew;
        if (cellDetails[i+1][j].f == FLT_MAX || cellDetails[i+1][j].f > fNew) {
          openList.insert(make_pair(fNew, make_pair(i+1, j)));
          cellDetails[i+1][j].f = fNew;
          cellDetails[i+1][j].g = gNew;
          cellDetails[i+1][j].h = hNew;
          cellDetails[i+1][j].parent_i = i;
          cellDetails[i+1][j].parent_j = j;
        }
      }
    }
    if (isValid(i, j+1)) {
      if (isDestination(i, j+1, dest)) {
        cellDetails[i][j+1].parent_i = i;
        cellDetails[i][j+1].parent_j = j;
        cout << "The Destination is found\n";
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
      } else if (!closedList[i][j+1] && isUnBlocked(i, j+1)) {
        gNew = cellDetails[i][j].g + 1.0;
        hNew = calHValue(i, j+1, dest);
        fNew = gNew + hNew;
        if (cellDetails[i][j+1].f == FLT_MAX || cellDetails[i][j+1].f > fNew) {
          openList.insert(make_pair(fNew, make_pair(i, j+1)));
          cellDetails[i][j+1].f = fNew;
          cellDetails[i][j+1].g = gNew;
          cellDetails[i][j+1].h = hNew;
          cellDetails[i][j+1].parent_i = i;
          cellDetails[i][j+1].parent_j = j;
        }
      }
    }
    if (isValid(i, j-1)) {
      if (isDestination(i, j-1, dest)) {
        cellDetails[i][j-1].parent_i = i;
        cellDetails[i][j-1].parent_j = j;
        cout << "The Destination is found\n";
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
      } else if (!closedList[i][j-1] && isUnBlocked(i, j-1)) {
        gNew = cellDetails[i][j].g + 1.0;
        hNew = calHValue(i, j-1, dest);
        fNew = gNew + hNew;
        if (cellDetails[i][j-1].f == FLT_MAX || cellDetails[i][j-1].f > fNew) {
          openList.insert(make_pair(fNew, make_pair(i, j-1)));
          cellDetails[i][j-1].f = fNew;
          cellDetails[i][j-1].g = gNew;
          cellDetails[i][j-1].h = hNew;
          cellDetails[i][j-1].parent_i = i;
          cellDetails[i][j-1].parent_j = j;
        }
      }
    }
    if (isValid(i-1, j+1)) {
      if (isDestination(i-1, j+1, dest)) {
        cellDetails[i-1][j+1].parent_i = i;
        cellDetails[i-1][j+1].parent_j = j;
        cout << "The Destination is found\n";
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
      } else if (!closedList[i-1][j+1] && isUnBlocked(i-1, j+1)) {
        gNew = cellDetails[i][j].g + 1.414;
        hNew = calHValue(i-1, j+1, dest);
        fNew = gNew + hNew;
        if (cellDetails[i-1][j+1].f == FLT_MAX || cellDetails[i-1][j+1].f > fNew) {
          openList.insert(make_pair(fNew, make_pair(i-1, j+1)));
          cellDetails[i-1][j+1].f = fNew;
          cellDetails[i-1][j+1].g = gNew;
          cellDetails[i-1][j+1].h = hNew;
          cellDetails[i-1][j+1].parent_i = i;
          cellDetails[i-1][j+1].parent_j = j;
        }
      }
    }
    if (isValid(i-1, j-1)) {
      if (isDestination(i-1, j-1, dest)) {
        cellDetails[i-1][j-1].parent_i = i;
        cellDetails[i-1][j-1].parent_j = j;
        cout << "The Destination is found\n";
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
      } else if (!closedList[i-1][j-1] && isUnBlocked(i-1, j-1)) {
        gNew = cellDetails[i][j].g + 1.414;
        hNew = calHValue(i-1, j-1, dest);
        fNew = gNew + hNew;
        if (cellDetails[i-1][j-1].f == FLT_MAX || cellDetails[i-1][j-1].f > fNew) {
          openList.insert(make_pair(fNew, make_pair(i-1, j-1)));
          cellDetails[i-1][j-1].f = fNew;
          cellDetails[i-1][j-1].g = gNew;
          cellDetails[i-1][j-1].h = hNew;
          cellDetails[i-1][j-1].parent_i = i;
          cellDetails[i-1][j-1].parent_j = j;
        }
      }
    }
    if (isValid(i+1, j+1)) {
      if (isDestination(i+1, j+1, dest)) {
        cellDetails[i+1][j+1].parent_i = i;
        cellDetails[i+1][j+1].parent_j = j;
        cout << "The Destination is found\n";
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
      } else if (!closedList[i+1][j+1] && isUnBlocked(i+1, j+1)) {
        gNew = cellDetails[i][j].g + 1.414;
        hNew = calHValue(i+1, j+1, dest);
        fNew = gNew + hNew;
        if (cellDetails[i+1][j+1].f == FLT_MAX || cellDetails[i+1][j+1].f > fNew) {
          openList.insert(make_pair(fNew, make_pair(i+1, j+1)));
          cellDetails[i+1][j+1].f = fNew;
          cellDetails[i+1][j+1].g = gNew;
          cellDetails[i+1][j+1].h = hNew;
          cellDetails[i+1][j+1].parent_i = i;
          cellDetails[i+1][j+1].parent_j = j;
        }
      }
    }
    if (isValid(i+1, j-1)) {
      if (isDestination(i+1, j-1, dest)) {
        cellDetails[i+1][j-1].parent_i = i;
        cellDetails[i+1][j-1].parent_j = j;
        cout << "The Destination is found\n";
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
      } else if (!closedList[i+1][j-1] && isUnBlocked(i+1, j-1)) {
        gNew = cellDetails[i][j].g + 1.414;
        hNew = calHValue(i+1, j-1, dest);
        fNew = gNew + hNew;
        if (cellDetails[i+1][j-1].f == FLT_MAX || cellDetails[i+1][j-1].f > fNew) {
          openList.insert(make_pair(fNew, make_pair(i+1, j-1)));
          cellDetails[i+1][j-1].f = fNew;
          cellDetails[i+1][j-1].g = gNew;
          cellDetails[i+1][j-1].h = hNew;
          cellDetails[i+1][j-1].parent_i = i;
          cellDetails[i+1][j-1].parent_j = j;
        }
      }
    }
  }
  if (!foundDest)
    cout << "Failed to find the Destination\n";
}

int main(void) {
  /*cin >> ROW >> COL;
  for (int i = 0; i < ROW; i++) {
    vector<int> v(COL);
    for (int j = 0; j < COL; j++)
      cin >> v[j];
    grid.push_back(v);
  }*/
  grid = {
    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
    { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
  };
  ROW = grid.size();
  COL = grid[0].size();
  pii src = make_pair(8, 0);
  pii dest = make_pair(0, 0);
  aStarSearch(src, dest);
}
