#include <iostream>
#include <numeric>
#include <string>

using namespace std;

string gcdOfStrings(string str1, string str2);
string gcdOfStrings2(string str1, string str2);

int main() {
    string str1 = "ABABABABAB", str2 = "ABAB";

    cout << "Str1: " << str1 << endl;
    cout << "Str2: " << str2 << endl;
    cout << "GCD:  " << gcdOfStrings(str1, str2) << endl;
    cout << "GCD2: " << gcdOfStrings2(str1, str2) << endl;

    return 0;
}

string gcdOfStrings(string str1, string str2) {
    if (str1.size() == 0 || str2.size() == 0) {
        return "";
    }

    string gcdStr = str1.size() < str2.size() ? str1 : str2;

    while (gcdStr.size() > 0) {
        if (str1.size() % gcdStr.size() != 0 || str2.size() % gcdStr.size() != 0) {
            gcdStr.erase(gcdStr.end() - 1);
            continue;
        }

        bool hasGcd = true;
        for (size_t i = 0; i < str1.size() || i < str2.size(); i++) {
            size_t t = i % gcdStr.size();

            if ((i < str1.size() && str1[i] != gcdStr[t]) ||
                (i < str2.size() && str2[i] != gcdStr[t])) {
                hasGcd = false;
                break;
            }
        }

        if (!hasGcd) {
            gcdStr.erase(gcdStr.end() - 1);
            continue;
        } else {
            break;
        }
    }

    return gcdStr;
}

string gcdOfStrings2(string str1, string str2) {
    if ((str1 + str2) != (str2 + str1)) {
        return "";
    }

    return str1.substr(0, gcd(str1.size(), str2.size()));
}
