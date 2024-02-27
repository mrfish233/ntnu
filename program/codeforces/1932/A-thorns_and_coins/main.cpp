#include <iostream>
#include <string>

using namespace std;

int maxCoin(string path);

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        string path;
        cin >> path;

        cout << maxCoin(path) << endl;
    }

    return 0;
}

int maxCoin(string path) {
    int coin = 0;
    bool spike = false;

    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '*') {
            if (spike) {
                break;
            }

            spike = true;
        } else {
            if (path[i] == '@') {
                coin++;
            }

            spike = false;
        }
    }

    return coin;
}
