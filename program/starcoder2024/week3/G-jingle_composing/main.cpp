#include <iostream>
#include <string>

using namespace std;

bool isRightDuration(string measure);
int totalRightDuration(string str);

int main() {
    string str;

    while (cin >> str && str != "*") {
        cout << totalRightDuration(str) << endl;
    }

    return 0;
}

bool isRightDuration(string measure) {
    int duration = 0;

    for (auto ch : measure) {
        if (ch == 'W') {
            duration += 64;
        } else if (ch == 'H') {
            duration += 32;
        } else if (ch == 'Q') {
            duration += 16;
        } else if (ch == 'E') {
            duration += 8;
        } else if (ch == 'S') {
            duration += 4;
        } else if (ch == 'T') {
            duration += 2;
        } else if (ch == 'X') {
            duration += 1;
        }

        if (duration > 64) {
            return false;
        }
    }

    return (duration == 64);
}

int totalRightDuration(string str) {
    string measure;
    int total = 0;

    for (size_t i = 1; i < str.length(); i++) {
        if (str[i] != '/') {
            measure += str[i];
        } else {
            total += isRightDuration(measure);
            measure = "";
        }
    }

    return total;
}
