#include <iostream>
#include <string>
#include <stack>

using namespace std;

string decodeString(string &s, size_t &i);
string decodeString(string s);

int main() {
    // string s = "abcdef";
    // string s = "xyz3[a]2[bc]";
    // string s = "3[a2[bc]]";
    // string s = "10[ab]";
    string s = "2[abc]3[de]fg";

    cout << decodeString(s) << endl;

    return 0;
}

string decodeString(string &s, size_t &i) {
    string str;

    while (i < s.length() && s[i] != ']') {
        // Add to string if it's alphabet
        if (isalpha(s[i])) {
            str += s[i++];
            continue;
        }

        // Find required times to loop if it is not alphabet
        int loop = 0;
        while (i < s.length() && isdigit(s[i])) {
            loop = loop * 10 + (s[i++] - '0');
        }

        // Recursion for strings inside bracket
        i++; // '['
        string subStr = decodeString(s, i);
        i++; // ']'

        // Add substrings to string for required times
        for (int j = 0; j < loop; j++) {
            str += subStr;
        }
    }

    return str;
}

string decodeString(string s) {
    // Recursion with overload function

    // size_t i = 0;
    // return decodeString(s, i);

    // ==============================

    // Stack

    stack<string> mystack;
    string currStr, currNum;

    for (size_t i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            currStr += s[i];
        } else if (isdigit(s[i])) {
            currNum += s[i];
        } else if (s[i] == '[') {
            mystack.push(currStr);
            mystack.push(currNum);

            currStr.clear();
            currNum.clear();
        } else if (s[i] == ']') {
            string tempStr;
            for (int i = 0; i < stoi(mystack.top()); i++) {
                tempStr += currStr;
            }
            mystack.pop();

            string prevStr = mystack.top();
            mystack.pop();

            // currStr.clear();
            currStr = prevStr + tempStr;
        }
    }

    return currStr;
}

// Recursion without overload function

// string decodeString(string s) {
//     string str = "";

//     for (size_t i = 0; i < s.length(); i++) {
//         if (s[i] == ']') {
//             // Return recursion
//             return str;
//         } else if (s[i] >= 'a' && s[i] <= 'z') {
//             // Add to result if it's alphabet
//             str += s[i];
//             continue;
//         }

//         // Loop number of times for strings inside bracket

//         int loop = 0;
//         while (s[i] != '[') {
//             loop = loop * 10 + (s[i++] - '0');
//         }

//         // Recursion for bracket of brackets

//         string tempStr(s.begin() + i + 1, s.end());
//         string subStr = decodeString(tempStr);

//         // Add substrings to result for required times

//         for (int j = 1; j <= loop; j++) {
//             str += subStr;
//         }

//         // Move i forward

//         int bracket = 1;
//         while (bracket > 0) {
//             i++;

//             if (s[i] == '[') {
//                 bracket++;
//             } else if (s[i] == ']') {
//                 bracket--;
//             }
//         }
//     }

//     return str;
// }
