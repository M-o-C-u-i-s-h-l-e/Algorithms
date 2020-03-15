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
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
  
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
