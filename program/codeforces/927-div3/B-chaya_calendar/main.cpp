#include <iostream>
#include <vector>

using namespace std;

int apocalypseYear(vector<int> signs);

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        vector<int> signs(m, 0);
        for (int i = 0; i < m; i++) {
            cin >> signs[i];
        }

        cout << apocalypseYear(signs) << endl;
    }

    return 0;
}

int apocalypseYear(vector<int> signs) {
    int year = signs[0];

    for (int i = 1; i < signs.size(); i++) {
        if (year % signs[i] == 0) {
            year += signs[i];
        } else {
            year += signs[i] - (year % signs[i]);
        }
    }

    return year;
}
