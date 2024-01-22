#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool canExchange(vector<int> loc, vector<int> tar);

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<int> loc(n, 0), tar(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> loc[i] >> tar[i];
        }

        if (canExchange(loc, tar)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

bool canExchange(vector<int> loc, vector<int> tar) {
    sort(loc.begin(), loc.end());
    sort(tar.begin(), tar.end());

    return (loc == tar);
}
