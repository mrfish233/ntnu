#include <iostream>
#include <string>
using namespace std;

char replace(char ch);
string decode(string str);

int main() {
    string str;

    getline(cin, str);
    cout << decode(str) << endl;

    return 0;
}

char replace(char ch) {
    if (ch >= '3' && ch <= '9') {
        ch -= 2;
    } else if (ch == '0') {
        ch = '8';
    } else if (ch == 'e' || ch == 'E') {
        ch = 'q';
    } else if (ch == 'r' || ch == 'R') {
        ch = 'w';
    } else if (ch == 't' || ch == 'T') {
        ch = 'e';
    } else if (ch == 'y' || ch == 'Y') {
        ch = 'r';
    } else if (ch == 'u' || ch == 'U') {
        ch = 't';
    } else if (ch == 'i' || ch == 'I') {
        ch = 'y';
    } else if (ch == 'o' || ch == 'O') {
        ch = 'u';
    } else if (ch == 'p' || ch == 'P') {
        ch = 'i';
    } else if (ch == '[' || ch == '{') {
        ch = 'o';
    } else if (ch == ']' || ch == '}') {
        ch = 'p';
    } else if (ch == 'd' || ch == 'D') {
        ch = 'a';
    } else if (ch == 'f' || ch == 'F') {
        ch = 's';
    } else if (ch == 'g' || ch == 'G') {
        ch = 'd';
    } else if (ch == 'h' || ch == 'H') {
        ch = 'f';
    } else if (ch == 'j' || ch == 'J') {
        ch = 'g';
    } else if (ch == 'k' || ch == 'K') {
        ch = 'h';
    } else if (ch == 'l' || ch == 'L') {
        ch = 'j';
    } else if (ch == ';' || ch == ':') {
        ch = 'k';
    } else if (ch == '\'' || ch == '\"') {
        ch = 'l';
    } else if (ch == '\\' || ch == '|') {
        ch = ';';
    } else if (ch == 'c' || ch == 'C') {
        ch = 'z';
    } else if (ch == 'v' || ch == 'V') {
        ch = 'x';
    } else if (ch == 'b' || ch == 'B') {
        ch = 'c';
    } else if (ch == 'n' || ch == 'N') {
        ch = 'v';
    } else if (ch == 'm' || ch == 'M') {
        ch = 'b';
    } else if (ch == ',' || ch == '<') {
        ch = 'n';
    } else if (ch == '.' || ch == '>') {
        ch = 'm';
    } else if (ch == '/' || ch == '?') {
        ch = ',';
    }

    return ch;
}

string decode(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = replace(str[i]);
    }

    return str;
}
