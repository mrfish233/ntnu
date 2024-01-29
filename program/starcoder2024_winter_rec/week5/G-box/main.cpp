#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool canMakeBox(vector<vector<int>> faces);

int main() {
    int w, l;
    vector<vector<int>> faces(6, vector<int>(2, 0));

    while (cin >> w >> l) {
        faces[0][0] = w;
        faces[0][1] = l;

        for (int i = 1; i < 6; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> faces[i][j];
            }
        }

        // cout << "{ ";
        // for (int i = 0; i < 6; i++) {
        //     cout << "[ ";
        //     for (int j = 0; j < 2; j++) {
        //         cout << faces[i][j] << " ";
        //     }
        //     cout << "] ";
        // }
        // cout << "}\n";

        if (canMakeBox(faces)) {
            cout << "POSSIBLE\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}

bool canMakeBox(vector<vector<int>> faces) {
    for (int i = 0; i < 6; i++) {
        if (faces[i][0] > faces[i][1]) {
            swap(faces[i][0], faces[i][1]);
        }
    }

    sort(faces.begin(), faces.end(),
        [](vector<int> a, vector<int> b) -> bool {
            return a[1] < b[1];
        }
    );

    sort(faces.begin(), faces.end(),
        [](vector<int> a, vector<int> b) -> bool {
            return a[0] < b[0];
        }
    );

    for (int i = 0; i < 6; i += 2) {
        if (faces[i] != faces[i+1]) {
            return false;
        }
    }

    if ((faces[0][0] != faces[2][0]) ||
        (faces[0][1] != faces[4][0]) ||
        (faces[2][1] != faces[4][1])) {
        return false;
    }

    return true;
}
