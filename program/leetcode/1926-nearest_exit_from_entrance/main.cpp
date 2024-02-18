#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printMaze(vector<vector<char>> maze);
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance);

int main() {
    int m, n, cases = 0;

    while (cin >> m >> n) {
        vector<vector<char>> maze(m, vector<char>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }

        vector<int> entrance(2, 0);
        cin >> entrance[0] >> entrance[1];

        int result = nearestExit(maze, entrance);
        printf("Case %d: %d\n", ++cases, result);
    }

    return 0;
}

void printMaze(vector<vector<char>> maze) {
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[0].size(); j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    const int n = maze.size();
    const int m = maze[0].size();

    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});

    maze[entrance[0]][entrance[1]] = '+';

    int length = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            if (!(i == entrance[0] && j == entrance[1]) &&
                (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                return length;
            }

            for (int k = 0; k < 4; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && maze[new_i][new_j] != '+') {
                    maze[new_i][new_j] = '+';

                    q.push({new_i, new_j});
                }
            }
        }

        length++;
    }

    return -1;
}
