#include <bits/stdc++.h>

using namespace std;

string removeSpoiler(string str) {
    int n = (int) str.length();
    int head = 0, len = 0, flag = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == '|') {
            if (flag == 0) {
                flag = 1;
                head = i;
            } else {
                len++;
                break;
            }
        }

        if (flag == 1) {
            len++;
        }
    }

    if (len != 0) {
        str.erase(head, len);
    }

    return str;
}

int main() {
    string str;
    while (cin >> str) {
        cout << removeSpoiler(str) << endl;
    }

    return 0;
}
