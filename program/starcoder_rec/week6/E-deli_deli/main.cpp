#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define SIN 0
#define PLU 1

int appendRules(string str);
void printPlural(string str, vector<vector<string>> irregular);

int main() {
    int L, N;
    cin >> L >> N;

    vector<vector<string>> irregular(L, vector<string>(2, ""));

    for (int i = 0; i < L; i++) {
        cin >> irregular[i][SIN] >> irregular[i][PLU];
    }

    while (N--) {
        string str;
        cin >> str;

        printPlural(str, irregular);
    }

    return 0;
}

int appendRules(string str) {
    int len = str.length();

    char last1 = str[len - 1];
    char last2 = str[len - 2];

    if ((last1 == 'y') && (last2 != 'a' && last2 != 'e' && last2 != 'i' && last2 != 'o' && last2 != 'u')) {
        return 1;
    } else if ((last1 == 'o') || (last1 == 's') || (last1 == 'x') ||
        (last2 == 'c' && last1 == 'h') || (last2 == 's' && last1 == 'h')) {
        return 2;
    } else {
        return 3;
    }
}

void printPlural(string str, vector<vector<string>> irregular) {
    for (int i = 0; i < irregular.size(); i++) {
        if (str == irregular[i][SIN]) {
            cout << irregular[i][PLU] << endl;
            return;
        }
    }

    int rule = appendRules(str);

    if (rule == 1) {
        str[str.length() - 1] = 'i';
    }

    if (rule == 1 || rule == 2) {
        str.push_back('e');
    }

    str.push_back('s');

    cout << str << endl;
}
