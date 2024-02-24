#include <iostream>
#include <string>
using namespace std;

string decode(string str);

int main() {
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        cout << "Case " << i << ": " << decode(str) << endl;
    }

    return 0;
}

string decode(string str) {
    if (str.length() == 0) {
        return "";
    }

    string result;

    char ch = str[0];
    int len = 0;

    for (int i = 1; i < str.length(); i++) {
        if (isdigit(str[i])) {
            len = len * 10 + str[i] - '0';
        } else {
            string temp(len, ch);
            result.append(temp);

            len = 0;
            ch  = str[i];
        }
    }

    string temp(len, ch);
    result.append(temp);

    return result;
}
