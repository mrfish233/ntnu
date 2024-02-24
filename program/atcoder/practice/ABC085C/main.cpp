#include <iostream>
#include <vector>

using namespace std;

vector<int> findValidBills(int n, int yen);

int main() {
    int n, y;
    while (cin >> n >> y) {
        vector<int> bills = findValidBills(n, y);

        for (int i = 0; i < 3; i++) {
            cout << bills[i];

            if (i != 2) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

vector<int> findValidBills(int n, int yen) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i + j > n) {
                break;
            }

            for (int k = 0; k <= n; k++) {
                if (i + j + k > n) {
                    break;
                }

                if ((i * 10000 + j * 5000 + k * 1000 == yen) && (i + j + k == n)) {
                    return {i, j, k};
                }
            }
        }
    }

    return {-1, -1, -1};
}

