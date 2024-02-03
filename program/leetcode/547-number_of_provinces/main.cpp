#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findCircleNum(vector<vector<int>>& isConnected);

int main() {
    int n;

    while (cin >> n) {
        vector<vector<int>> isConnected(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> isConnected[i][j];
            }
        }

        cout << "{ ";
        for (int i = 0; i < (int) isConnected.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < (int) isConnected[i].size(); j++) {
                cout << isConnected[i][j] << " ";
            }
            cout << "] ";
        }
        cout << "}\n";

        cout << findCircleNum(isConnected) << endl;
    }

    return 0;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int province = 0;

    vector<bool> connect(isConnected.size(), false);
    queue<int> cities;

    for (int i = 0; i < (int) isConnected.size(); i++) {
        if (connect[i]) {
            continue;
        }

        province++;

        cities.push(i);

        while (!cities.empty()) {
            int city = cities.front();

            connect[city] = true;

            for (int j = 0; j < (int) isConnected[city].size(); j++) {
                if (isConnected[city][j] && !connect[j]) {
                    cities.push(j);
                }
            }

            cities.pop();
        }
    }

    return province;
}
