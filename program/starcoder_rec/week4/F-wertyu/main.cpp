#include <iostream>
#include <string>
using namespace std;

char replace(char ch);
string decode(string str);

int main() {
    string str;

    while (getline(cin, str)) {
        cout << decode(str) << endl;
    }

    return 0;
}

char replace(char ch) {
    if (ch >= '2' && ch <= '9') {
        ch -= 1;
    } else if (ch == '1') {
        ch = '`';
    } else if (ch == '0') {
        ch = '9';
    } else if (ch == '-') {
        ch = '0';
    } else if (ch == '=') {
        ch = '-';
    } else if (ch == 'W') {
        ch = 'Q';
    } else if (ch == 'E') {
        ch = 'W';
    } else if (ch == 'R') {
        ch = 'E';
    } else if (ch == 'T') {
        ch = 'R';
    } else if (ch == 'Y') {
        ch = 'T';
    } else if (ch == 'U') {
        ch = 'Y';
    } else if (ch == 'I') {
        ch = 'U';
    } else if (ch == 'O') {
        ch = 'I';
    } else if (ch == 'P') {
        ch = 'O';
    } else if (ch == '[') {
        ch = 'P';
    } else if (ch == ']') {
        ch = '[';
    } else if (ch == '\\') {
        ch = ']';
    } else if (ch == 'S') {
        ch = 'A';
    } else if (ch == 'D') {
        ch = 'S';
    } else if (ch == 'F') {
        ch = 'D';
    } else if (ch == 'G') {
        ch = 'F';
    } else if (ch == 'H') {
        ch = 'G';
    } else if (ch == 'J') {
        ch = 'H';
    } else if (ch == 'K') {
        ch = 'J';
    } else if (ch == 'L') {
        ch = 'K';
    } else if (ch == ';') {
        ch = 'L';
    } else if (ch == '\'') {
        ch = ';';
    } else if (ch == 'X') {
        ch = 'Z';
    } else if (ch == 'C') {
        ch = 'X';
    } else if (ch == 'V') {
        ch = 'C';
    } else if (ch == 'B') {
        ch = 'V';
    } else if (ch == 'N') {
        ch = 'B';
    } else if (ch == 'M') {
        ch = 'N';
    } else if (ch == ',') {
        ch = 'M';
    } else if (ch == '.') {
        ch = ',';
    } else if (ch == '/') {
        ch = '.';
    }

    return ch;
}

string decode(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = replace(str[i]);
    }

    return str;
}
