#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms);

int main() {
    int n, k;

    while (cin >> n) {
        vector<vector<int>> rooms(n);

        for (int i = 0; i < n; i++) {
            cin >> k;
            vector<int> keys(k, 0);

            for (int j = 0; j < k; j++) {
                cin >> keys[j];
            }

            rooms[i] = keys;
        }

        cout << "{ ";
        for (int i = 0; i < (int) rooms.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < (int) rooms[i].size(); j++) {
                cout << rooms[i][j] << " ";
            }
            cout << "] ";
        }
        cout << "}\n";

        cout << canVisitAllRooms(rooms) << endl;
    }

    return 0;
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    if (rooms.size() == 0) {
        return false;
    } else if (rooms.size() == 1) {
        return true;
    }

    vector<bool> openRooms(rooms.size(), false);
    queue<int> keys;

    keys.push(0);

    while (!keys.empty()) {
        int key = keys.front();

        openRooms[key] = true;

        for (int i = 0; i < (int) rooms[key].size(); i++) {
            int k = rooms[key][i];

            if (!openRooms[k]) {
                keys.push(k);
            }
        }

        keys.pop();
    }

    for (int i = 0; i < (int) openRooms.size(); i++) {
        if (!openRooms[i]) {
            return false;
        }
    }

    return true;
}
