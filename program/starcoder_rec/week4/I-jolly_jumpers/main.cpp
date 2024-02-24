#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isJollyJumper(vector<int> num);

int main() {
    int n;
    while (cin >> n) {
        vector<int> num(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        if (isJollyJumper(num)) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }

    return 0;
}

bool isJollyJumper(vector<int> num) {
    if (num.size() == 1) {
        return true;
    }

    vector<bool> diff(num.size(), 0);

    for (int i = 1; i < num.size(); i++) {
        int d = abs(num[i-1] - num[i]);
        if (d == 0 || diff[d]) {
            return false;
        }

        diff[d] = true;
    }

    for (int i = 1; i < diff.size(); i++) {
        if (!diff[i]) {
            return false;
        }
    }

    return true;
}
