#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int findVolume(vector<vector<int>> &grid, int x, int y);
int findLargestVolume(vector<vector<int>> grid);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        printf("%d\n", findLargestVolume(grid));
    }

    return 0;
}

int findVolume(vector<vector<int>> &grid, int x, int y) {
    int n = (int) grid.size();
    int m = (int) grid[0].size();

    if (x < 0 || x > n-1 || y < 0 || y > m-1 || grid[x][y] == 0) {
        return 0;
    }

    int volume = grid[x][y];
    grid[x][y] = 0;

    volume += findVolume(grid, x-1, y);
    volume += findVolume(grid, x+1, y);
    volume += findVolume(grid, x, y-1);
    volume += findVolume(grid, x, y+1);

    // const int dx[] = {-1, 1, 0, 0};
    // const int dy[] = {0, 0, -1, 1};
    //
    // for (int i = 0; i < 4; i++) {
    //     int new_x = x + dx[i];
    //     int new_y = y + dy[i];
    //
    //     volume += findVolume(grid, new_x, new_y);
    // }

    return volume;
}

int findLargestVolume(vector<vector<int>> grid) {
    int n = (int) grid.size();
    int m = (int) grid[0].size();

    int volume = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                continue;
            }

            int temp = findVolume(grid, i, j);
            volume = max(volume, temp);
        }
    }

    return volume;
}

