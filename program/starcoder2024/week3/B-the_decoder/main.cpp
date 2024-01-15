#include <iostream>
#include <string>

using namespace std;

void decode(string str);

int main() {
    string str;

    while (cin >> str) {
        decode(str);
    }

    return 0;
}

void decode(string str) {
    for (auto ch : str) {
        char c = ch - 7;
        cout << c;
    }
    cout << endl;
}
