#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>> &grid);

int main() {
    int m, n, cases = 0;

    while (cin >> m >> n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        int result = orangesRotting(grid);
        printf("Case %d: %d\n", ++cases, result);
    }

    return 0;
}

int orangesRotting(vector<vector<int>> &grid) {
    const int EMPTY  = 0;
    const int FRESH  = 1;
    const int ROTTEN = 2;

    const int n = grid.size();
    const int m = grid[0].size();
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    int fresh = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == FRESH) {
                fresh++;
            } else if (grid[i][j] == ROTTEN) {
                q.push({i, j});
            }
        }
    }

    if (!fresh) {
        return 0;
    }

    int time = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for (int k = 0; k < 4; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == FRESH) {
                    grid[new_i][new_j] = ROTTEN;

                    q.push({new_i, new_j});
                    fresh--;
                }
            }
        }

        time++;
    }

    if (fresh) {
        return -1;
    }

    return time - 1;
}
