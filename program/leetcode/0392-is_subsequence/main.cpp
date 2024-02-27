#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(string s, string t);

int main() {
    string s = "agc", t = "ahbgdc";

    cout << isSubsequence(s, t) << endl;

    return 0;
}

bool isSubsequence(string s, string t) {
    if (s.length() == 0) {
        return true;
    }

    size_t j = 0;

    for (size_t i = 0; i < t.length(); i++) {
        if (s[j] == t[i]) {
            j++;

            if (j == s.length()) {
                return true;
            }
        }
    }

    return false;
}
