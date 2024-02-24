#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isValidASCII(char ch);
void printFreq(string str);

int main() {
    int print = 0;
    string str;

    while (getline(cin, str)) {
        if (print) {
            printf("\n");
        }

        printFreq(str);
        print = 1;
    }

    return 0;
}

bool isValidASCII(char ch) {
    return (ch >= 32 && ch <= 127);
}

void printFreq(string str) {
    vector<vector<int>> ascii;

    for (int i = 0; i < str.size(); i++) {
        bool flag = false;

        for (int j = 0; j < ascii.size(); j++) {
            if (ascii[j][0] == str[i]) {
                ascii[j][1]++;
                flag = true;
                break;
            }
        }

        if (!flag && isValidASCII(str[i])) {
            ascii.push_back({str[i], 1});
        }
    }

    sort(ascii.begin(), ascii.end(), [](vector<int> a, vector<int> b) -> bool {
        return a[0] > b[0];
    });

    stable_sort(ascii.begin(), ascii.end(), [](vector<int> a, vector<int> b) -> bool {
        return a[1] < b[1];
    });

    for (int i = 0; i < ascii.size(); i++) {
        printf("%d %d\n", ascii[i][0], ascii[i][1]);
    }
}
