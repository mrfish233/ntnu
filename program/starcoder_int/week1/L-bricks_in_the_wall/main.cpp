#include <iostream>
#include <vector>
using namespace std;

void addBricks(vector<vector<int>> &bricks);

int main() {
    int n;
    cin >> n;

    while (n--) {
        vector<vector<int>> bricks(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i += 2) {
            for (int j = 0; j <= i; j += 2) {
                cin >> bricks[i][j];
            }
        }

        addBricks(bricks);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j <= i; j++) {
                if (j != 0) {
                    cout << " ";
                }
                cout << bricks[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}

void addBricks(vector<vector<int>> &bricks) {
    for (int i = 1; i <= 7; i += 2) {
        bricks[8][i] = (bricks[6][i-1] - bricks[8][i-1] - bricks[8][i+1]) / 2;
    }

    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            bricks[i][j] = bricks[i+1][j] + bricks[i+1][j+1];
        }
    }
}
