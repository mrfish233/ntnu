#include <iostream>
#include <string>

using namespace std;

string reverseWords(string s);

int main() {
    string str = "  asdf  aaa ss  ";

    cout << str << endl;
    cout << reverseWords(str) << endl;

    return 0;
}

string reverseWords(string s) {
    string result = "";

    string::iterator tail = s.end() - 1, head;

    while (tail != s.begin() - 1) {
        if (*tail == ' ') {
            tail--;
            continue;
        }

        head = tail;
        while (head != s.begin() && *(head - 1) != ' ') {
            head--;
        }

        result.append(head, tail + 1);
        result.append(" ");

        if (head == s.begin()) {
            break;
        }

        tail = head - 1;
    }

    result.pop_back();

    return result;
}
