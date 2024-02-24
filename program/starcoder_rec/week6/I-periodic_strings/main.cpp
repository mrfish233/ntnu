#include <iostream>
#include <string>
using namespace std;

int smallestPeriodLength(string str);

int main() {
    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        cout << smallestPeriodLength(str) << endl;

        if (n) {
            cout << endl;
        }
    }

    return 0;
}

int smallestPeriodLength(string str) {
    if (str.length() == 0) {
        return 0;
    }

    string temp;
    bool isPeriod = false;

    while (!isPeriod) {
        isPeriod = true;

        temp.push_back(str[temp.length()]);

        if (str.length() % temp.length()) {
            isPeriod = false;
            continue;
        }

        int len = str.length() / temp.length();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < temp.length(); j++) {
                int idx = i * temp.length() + j;

                if (temp[j] != str[idx]) {
                    isPeriod = false;
                    break;
                }
            }

            if (!isPeriod) {
                break;
            }
        }
    }

    return temp.length();
}
