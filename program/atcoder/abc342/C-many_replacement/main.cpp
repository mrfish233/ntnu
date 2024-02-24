#include <iostream>
#include <vector>
#include <string>

using namespace std;

void build(vector<char> &change, char c, char d);
void replace(string &str, vector<char> change);

int main() {
    int n, q;
    string str;
    cin >> n >> str >> q;

    vector<char> change(26, 0);

    for (int i = 0; i < 26; i++) {
        change[i] = i + 'a';
    }

    while (q--) {
        char c, d;
        cin >> c >> d;

        build(change, c, d);
    }

    replace(str, change);
    cout << str << "\n";

    return 0;
}

void build(vector<char> &change, char c, char d) {
    for (int i = 0; i < 26; i++) {
        if (change[i] == c) {
            change[i] = d;
        }
    }

    // for (int i = 0; i < 26; i++) {
    //     if (i % 5 == 0) {
    //         cout << " ";
    //     }

    //     cout << change[i];
    // }
    // cout << '\n';
}

void replace(string &str, vector<char> change) {
    for (int i = 0; i < (int) str.length(); i++) {
        int tmp = str[i] - 'a';

        str[i] = change[tmp];
    }
}
