#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch);
string reverseVowels(string s);

int main() {
    string s = "AEIOUXaeiou";

    cout << "Before: " << s << endl;
    cout << "After:  " << reverseVowels(s) << endl;
    cout << "After2: " << s << endl;

    return 0;
}

bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

string reverseVowels(string s) {
    string::iterator head = s.begin();
    string::iterator tail = s.end() - 1;

    while (head < tail) {
        if (!isVowel(*head)) {
            head++;
        }

        if (!isVowel(*tail)) {
            tail--;
        }

        if (isVowel(*head) && isVowel(*tail)) {
            swap(*head, *tail);

            head++;
            tail--;
        }
    }

    return s;
}
