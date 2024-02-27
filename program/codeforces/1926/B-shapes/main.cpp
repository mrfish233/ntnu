#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSquare(vector<string> grid);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> grid(n, "");

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        if (isSquare(grid)) {
            cout << "SQUARE\n";
        } else {
            cout << "TRIANGLE\n";
        }
    }

    return 0;
}

bool isSquare(vector<string> grid) {
    for (int i = 0; i < grid.size(); i++) {
        int count = 0;

        for (int j = 0; j < grid[i].length(); j++) {
            if (grid[i][j] == '1') {
                count++;
            }
        }

        if (count == 1) {
            return false;
        }
    }

    return true;
}
