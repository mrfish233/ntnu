#include <iostream>
#include <vector>

using namespace std;

bool isValidPlan(vector<vector<int>> plans);

int main() {
    int n;
    
    while (cin >> n) {
        vector<vector<int>> plans(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> plans[i][j];
            }
        }

        if (isValidPlan(plans)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}

bool isValidPlan(vector<vector<int>> plans) {
    int x = 0, y = 0, t = 0, d = 0;

    for (auto plan : plans) {
        d = abs(plan[1] - x) + abs(plan[2] - y);
        t = plan[0] - t;

        if (t < d) {
            return false;
        }

        if ((d + t) % 2) {
            return false;
        }

        t = plan[0];
        x = plan[1];
        y = plan[2];
    }

    return true;
}

