#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isWord(string str, int idx, string word);
bool canAppendTo(string str);

int main() {
    string str;
    while (cin >> str) {
        if (canAppendTo(str)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

bool isWord(string str, int idx, string word) {
    int len = (int) word.length();

    if (idx + len > (int) str.length()) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (str[idx + i] != word[i]) {
            return false;
        }
    }

    return true;
}

bool canAppendTo(string str) {
    vector<string> words = {
        "eraser", "erase", "dreamer", "dream"
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < (int) str.length(); j++) {
            if (isWord(str, j, words[i])) {
                str.erase(j, words[i].length());
                j--;
            }
        }
    }

    // cout << "Result: " << str << endl;

    if (str.empty()) {
        return true;
    }

    return false;
}

