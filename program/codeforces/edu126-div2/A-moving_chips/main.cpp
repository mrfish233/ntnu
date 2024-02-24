#include <iostream>
#include <vector>

using namespace std;

int minOperation(vector<int> cells);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> cells(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> cells[i];
        }

        cout << minOperation(cells) << endl;
    }

    return 0;
}

int minOperation(vector<int> cells) {
    bool flag = false;
    int hole = 0, temp = 0;

    for (int i = 0; i < cells.size(); i++) {
        if (cells[i]) {
            flag = true;
            hole += temp;
            temp = 0;
        } else if (flag) {
            temp++;
        }
    }

    return hole;
}
