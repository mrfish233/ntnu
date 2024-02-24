#include <iostream>
#include <string>
#include <map>

using namespace std;

int findDiffChar(string str);

int main() {
    string str;
    while (cin >> str) {
        cout << findDiffChar(str) << endl;
    }

    return 0;
}

int findDiffChar(string str) {
    map<char, int> check;
    int n = (int) str.length();

    for (int i = 0; i < n; i++) {
        check[str[i]]++;
    }

    char find = 0;

    for (auto it = check.begin(); it != check.end(); it++) {
        if (it->second == 1) {
            find = it->first;
        }
    }

    int pos = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == find) {
            pos = i + 1;
            break;
        }
    }

    return pos;
}
