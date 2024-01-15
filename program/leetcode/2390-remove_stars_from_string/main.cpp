#include <iostream>
#include <string>

using namespace std;

string removeStars(string s);

int main() {
    string s = "leet**cod*e";
    // string s = "erase*****";

    cout << "Before: '" << s << "'\n";
    cout << "After:  '" << removeStars(s) << "'\n";

    return 0;
}

string removeStars(string s) {
    string result = "";

    for (auto ch : s) {
        if (ch == '*') {
            result.pop_back();
        } else {
            result.push_back(ch);
        }
    }

    return result;

    // =================================

    // TLE as erase() requires a long time

    // for (size_t i = 0; i < s.length(); i++) {
    //     if (s[i] == '*') {
    //         s.erase(i-1, 2);
    //         i -= 2;
    //     }
    // }

    // return s;
}
