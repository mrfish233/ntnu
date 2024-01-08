#include <iostream>
#include <string>

using namespace std;

int score(string str);

int main() {
    int cases = 0;
    cin >> cases;

    while (cases--) {
        string str;
        cin >> str;

        cout << score(str) << endl;
    }

    return 0;
}

int score(string str) {
    int total = 0, point = 1;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == 'O') {
            total += point;
            point++;
        } else {
            point = 1;
        }
    }

    return total;
}
