#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool hasArray(string str);

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        if (hasArray(str)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

bool hasArray(string str) {
    int n = 0;

    for (auto ch : str) {
        if (ch == 'N') {
            n++;
        }
    }

    if (n == 1) {
        return false;
    }

    return true;
}

