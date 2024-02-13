#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define L 0
#define H 1

int findValidPrice(vector<vector<int>> prices, int target);

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        vector<string> names(m);
        vector<vector<int>> prices(m, vector<int>(2, 0));

        for (int i = 0; i < m; i++) {
            cin >> names[i] >> prices[i][L] >> prices[i][H];
        }

        int q;
        cin >> q;

        while (q--) {
            int target;
            cin >> target;

            int res = findValidPrice(prices, target);

            if (res == -1) {
                cout << "UNDETERMINED\n";
            } else {
                cout << names[res] << endl;
            }
        }

        if (n != 0) {
            cout << endl;
        }
    }

    return 0;
}

int findValidPrice(vector<vector<int>> prices, int target) {
    int res = -1;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i][L] <= target && target <= prices[i][H]) {
            if (res != -1) {
                return -1;
            } else {
                res = i;
            }
        }
    }

    return res;
}
