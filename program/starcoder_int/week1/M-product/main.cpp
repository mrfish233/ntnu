#include <iostream>
#include <string>
using namespace std;

int parseInt(int ch);

string product(string x, string y);
string productDigit(string x, char digit);
string sum(string x, string y);

int main() {
    string x, y;

    while (cin >> x >> y) {
        cout << product(x, y) << endl;
    }

    return 0;
}

int parseInt(int ch) {
    if (isdigit(ch)) {
        return (ch - '0');
    } else if (ch <= 9) {
        return (ch + '0');
    }

    return -1;
}

string product(string x, string y) {
    string result = "0";

    for (int i = (int) y.length() - 1; i >= 0; i--) {
        string temp = productDigit(x, y[i]);

        // cout << temp << endl;

        for (int j = 0; j < (int) y.length() - i - 1; j++) {
            temp += "0";
        }

        result = sum(result, temp);
    }

    while (result[0] == '0' && result.length() > 1) {
        result.erase(0, 1);
    }

    return result;
}

string productDigit(string str, char ch) {
    if (ch == '0') {
        return "0";
    }

    string result = "0" + str;
    int carry = 0, temp = 0, digit = parseInt(ch);

    for (int i = (int) str.length() - 1; i >= 0; i--) {
        temp  = parseInt(str[i]) * digit + carry;
        carry = temp / 10;
        // result = to_string(temp % 10) + result;
        result[i+1] = parseInt(temp % 10);
    }

    if (carry != 0) {
        result[0] = parseInt(carry % 10);
    } else {
        result = result.erase(0, 1);
    }

    return result;
}

string sum(string x, string y) {
    string result = "0";

    int i = (int) x.length() - 1;
    int j = (int) y.length() - 1;

    if (i > j) {
        result += x;
    } else {
        result += y;
    }

    int k = (int) result.length() - 1;

    int carry = 0, temp = 0;

    while (i >= 0 || j >= 0) {
        int digitX = (i >= 0) ? parseInt(x[i]) : 0;
        int digitY = (j >= 0) ? parseInt(y[j]) : 0;

        temp  = digitX + digitY + carry;
        carry = temp / 10;
        result[k] = parseInt(temp % 10);

        i--, j--, k--;
    }

    if (carry != 0) {
        result[0] = parseInt(carry % 10);
    } else {
        result.erase(0, 1);
    }

    return result;
}
