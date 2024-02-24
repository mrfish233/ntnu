#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printRotated(vector<string> str);

int main() {
    vector<string> str;
    string s;

    while (getline(cin, s)) {
        str.push_back(s);
    }

    printRotated(str);

    return 0;
}

void printRotated(vector<string> str) {
    if (str.empty()) {
        return;
    }

    int len = 0;

    for (int i = 0; i < str.size(); i++) {
        len = max(len, (int) str[i].size());
    }

    for (int i = 0; i < len; i++) {
        for (int j = str.size() - 1; j >= 0; j--) {
            if (i < str[j].length()) {
                cout << str[j][i];
            } else if (j != 0) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
