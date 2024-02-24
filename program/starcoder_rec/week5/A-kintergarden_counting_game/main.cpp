#include <iostream>
#include <string>
using namespace std;

int wordCount(string str);

int main() {
    string str;

    while (getline(cin, str)) {
        cout << wordCount(str) << endl;
    }

    return 0;
}

int wordCount(string str) {
    if (str.empty()) {
        return 0;
    }

    int count = 0;
    bool hasAlpha = false;

    for (int i = 0; i < (int) str.length(); i++) {
        if (isalpha(str[i])) {
            hasAlpha = true;
        } else if (hasAlpha) {
            hasAlpha = false;
            count++;
        }
    }

    return count;
}
