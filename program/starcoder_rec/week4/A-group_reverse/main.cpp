#include <iostream>
#include <string>
using namespace std;

string groupReverse(string str, int group);

int main() {
    int n = 0;
    string str;

    while (cin >> n && n != 0) {
        cin >> str;

        cout << groupReverse(str, n) << endl;
    }

    return 0;
}

string groupReverse(string str, int group) {
    size_t len = str.length() / group;

    for (size_t i = 0; i < str.length(); i += len) {
        for (size_t j = 0; j < len / 2; j++) {
            size_t head = i + j;
            size_t tail = i + len - j - 1;

            swap(str[head], str[tail]);
        }
    }

    return str;
}
