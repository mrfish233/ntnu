#include <iostream>
#include <string>
#include <vector>

using namespace std;

int equalPairs(vector<vector<int>>& grid);

void printVector(vector<string> &str) {
    cout << "[ ";
    for (auto i : str) {
        cout << i << ' ';
    }
    cout << "]" << endl;
}

int main() {
    // vector<vector<int>> grid = {
    //     {3,2,1},
    //     {1,7,6},
    //     {2,7,7},
    // };
    // vector<vector<int>> grid = {
    //     {3,1,2,2},
    //     {1,4,4,5},
    //     {2,4,2,2},
    //     {2,4,2,2}
    // };
    vector<vector<int>> grid = {
        {1,11},
        {11,1},
    };

    cout << equalPairs(grid) << endl;

    return 0;
}

int equalPairs(vector<vector<int>>& grid) {
    vector<string> row(grid.size(), "");
    vector<string> col(grid.size(), "");

    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
            row[i] += to_string(grid[i][j]) + "-";
            col[i] += to_string(grid[j][i]) + "-";
        }
    }

    int pair = 0;

    for (size_t i = 0; i < row.size(); i++) {
        for (size_t j = 0; j < col.size(); j++) {
            pair += (row[i] == col[j]);
        }
    }

    return pair;
}
