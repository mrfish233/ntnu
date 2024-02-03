#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printConnections(vector<vector<int>> connections) {
    cout << "{ ";
    for (int i = 0; i < (int) connections.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < (int) connections[i].size(); j++) {
            cout << connections[i][j] << " ";
        }
        cout << "] ";
    }
    cout << "}\n";
}

int minReorder(int n, vector<vector<int>> &connections);

int main() {
    int n;

    while (cin >> n) {
        vector<vector<int>> connections(n - 1, vector<int>(2, 0));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> connections[i][j];
            }
        }

        // printConnections(connections);
        cout << minReorder(n, connections) << endl;
    }

    return 0;
}

int minReorder(int n, vector<vector<int>> &connections) {
    int reorder = 0;
    queue<pair<int, int>> route;
    vector<bool> check(n-1, false);

    for (int i = 0; i < n-1; i++) {
        if (connections[i][0] == 0 || connections[i][1] == 0) {
            route.push({i, 0});
        }
    }

    while (!route.empty()) {
        int r    = route.front().first;
        int city = route.front().second;

        if (connections[r][0] == city) {
            city = connections[r][1];
            reorder++;
        } else {
            city = connections[r][0];
        }

        check[r] = true;

        for (int i = 0; i < n-1; i++) {
            if (check[i]) {
                continue;
            }

            if (connections[i][0] == city || connections[i][1] == city) {
                route.push({i, city});
            }
        }

        route.pop();
    }

    return reorder;
}
