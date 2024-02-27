#include <iostream>
#include <string>

using namespace std;

char appearMost(string str);

int main() {
    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        cout << appearMost(str) << endl;
    }

    return 0;
}

char appearMost(string str) {
    int a = 0, b = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'A') {
            a++;
        } else {
            b++;
        }
    }

    if (a > b) {
        return 'A';
    } else {
        return 'B';
    }
}
