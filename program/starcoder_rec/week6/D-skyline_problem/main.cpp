#include <iostream>
#include <vector>
using namespace std;

#define L 0
#define H 1
#define R 2

vector<int> findHeight(vector<vector<int>> buildings);
void drawSkyline(vector<vector<int>> buildings);

int main() {
    int l, h, r;
    vector<vector<int>> buildings;

    while (cin >> l >> h >> r) {
        buildings.push_back({l, h, r});
    }

    drawSkyline(buildings);

    return 0;
}

vector<int> findHeight(vector<vector<int>> buildings) {
    if (buildings.empty()) {
        return {};
    }

    vector<int> height(10000, 0);

    for (int i = 0; i < buildings.size(); i++) {
        int left  = buildings[i][L];
        int right = buildings[i][R];

        for (int j = left; j < right; j++) {
            if (height[j] < buildings[i][H]) {
                height[j] = buildings[i][H];
            }
        }
    }

    return height;
}

void drawSkyline(vector<vector<int>> buildings) {
    vector<int> height = findHeight(buildings);

    // cout << "[ ";
    // for (int i = 0; i < height.size(); i++) {
    //     cout << height[i] << " ";
    // }
    // cout << "]\n";

    int curr = 0, print = 0;

    for (int i = 1; i < height.size(); i++) {
        if (height[i] == curr) {
            continue;
        }

        if (print) {
            cout << " ";
        }

        cout << i << " " << height[i];

        curr  = height[i];
        print = 1;
    }
    cout << endl;
}
