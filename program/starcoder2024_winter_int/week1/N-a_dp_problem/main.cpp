#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void solveLinearEquation(string str);

int main() {
    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;
        solveLinearEquation(str);
    }

    return 0;
}

void solveLinearEquation(string str) {
    int x = 0, c = 0, sign = 1, equal = 1, curr = 0, len = 0;

    for (char ch : str) {
        // cout << ch << ": ";

        if (isdigit(ch)) {
            curr = curr * 10 + (ch - '0');
            len++;
        } else if (ch == 'x') {
            if (len == 0) {
                x += 1 * sign * equal;
            } else {
                x += curr * sign * equal;
            }
            curr = 0;
            len = 0;
        } else if (ch == '+' || ch ==  '-' || ch == '=') {
            c += curr * sign * (-equal);
            curr = 0;
            len = 0;

            if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else if (ch == '=') {
                equal = -1;
                sign = 1;
            }
        }

        // cout << curr << "; " << x << "x; " << c << "; " << sign << "; " << equal << ";\n"; 
    }

    if (curr != 0) {
        c += curr * sign * (-equal);
    }

    if (x == 0 && c == 0) {
        cout << "IDENTITY\n";
    } else if (x == 0 && c != 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        double num = (double) c / x;
        cout << floor(num) + 0.0 << endl;
    }
}
