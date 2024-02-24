#include <iostream>
#include <string>
#include <vector>
using namespace std;

char calculateMine(vector<string> field, int x, int y);
void sweep(vector<string> &field);

int main() {
    int m, n, i = 0;

    while (cin >> m >> n && m != 0 && n != 0) {
        vector<string> field(m, "");
        for (int i = 0; i < m; i++) {
            cin >> field[i];
        }

        sweep(field);

        if (i != 0) {
            cout << endl;
        }

        cout << "Field #" << ++i << ":\n";
        for (int i = 0; i < m; i++) {
            cout << field[i] << endl;
        }
    }

    return 0;
}

char calculateMine(vector<string> field, int x, int y) {
    int mine = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        if (i < 0 || i >= field.size()) {
            continue;
        }

        for (int j = y - 1; j <= y + 1; j++) {
            if (j < 0 || j >= field[i].length()) {
                continue;
            }

            if (field[i][j] == '*') {
                mine++;
            }
        }
    }

    return mine + '0';
}

void sweep(vector<string> &field) {
    for (int i = 0; i < field.size(); i++) {
        for (int j = 0; j < field[i].length(); j++) {
            if (field[i][j] == '*') {
                continue;
            }

            field[i][j] = calculateMine(field, i, j);
        }
    }
}
