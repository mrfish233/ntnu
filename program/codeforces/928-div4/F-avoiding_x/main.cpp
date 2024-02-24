#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isCross(vector<string> grid, int x, int y);
int findCross(vector<string> grid, vector<vector<int>> &cross);
void removeCross(vector<string> &grid, vector<vector<int>> &cross);
void cleanCross(vector<vector<int>> &cross);
int minOperations(vector<string> grid);

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<string> grid(7, "");

        for (int i = 0; i < 7; i++) {
            cin >> grid[i];
        }

        cout << minOperations(grid) << endl;
    }

    return 0;
}

bool isCross(vector<string> grid, int x, int y) {
    if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid.size() - 1 || grid[x][y] == 'W') {
        return false;
    }

    char a = grid[x-1][y-1];
    char b = grid[x+1][y-1];
    char c = grid[x-1][y+1];
    char d = grid[x+1][y+1];

    if (a == 'B' && b == 'B' && c == 'B' && d == 'B') {
        return true;
    }

    return false;
}

int findCross(vector<string> grid, vector<vector<int>> &cross) {
    int count = 0;

    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            if (isCross(grid, i, j)) {
                cross[i][j]++;
                cross[i-1][j-1]++;
                cross[i-1][j+1]++;
                cross[i+1][j-1]++;
                cross[i+1][j+1]++;

                count++;
            }
        }
    }

    return count;
}

void removeCross(vector<string> &grid, vector<vector<int>> &cross) {
    int tmp = 0, x = 0, y = 0;

    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            if (tmp <= cross[i][j]) {
                tmp = cross[i][j];

                x = i;
                y = j;
            }
        }
    }

    grid[x][y] = 'W';
}

void cleanCross(vector<vector<int>> &cross) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cross[i][j] = 0;
        }
    }
}

int minOperations(vector<string> grid) {
    vector<vector<int>> cross(7, vector<int>(7, 0));

    int operation = 0;
    int hasCross  = findCross(grid, cross);

    while (hasCross) {
        removeCross(grid, cross);
        operation++;

        cleanCross(cross);
        hasCross = findCross(grid, cross);
    }

    return operation;
}
