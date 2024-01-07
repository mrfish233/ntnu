#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void updateVector(vector<char>& chars, int &size, char ch, int len);
int compress(vector<char>& chars);

int main() {
    // vector<char> chars = {'a','c','b','b','d','d','e'};
    vector<char> chars = {'a','a','b','b','b','b','b','b','b','b','b','b','b','b'};

    int length = chars.size();

    cout << "Before: ";
    for (int i = 0; i < length; i++) {
        cout << chars[i];
    }
    cout << endl;

    length = compress(chars);

    cout << "After:  ";
    for (int i = 0; i < length; i++) {
        cout << chars[i];
    }
    cout << endl;

    return 0;
}

void updateVector(vector<char> &chars, int &size, char ch, int len) {
    chars[size++] = ch;

    if (len == 1) {
        return;
    }

    int digits = 0, pow10 = 1, temp = len;
    while (temp > 0) {
        digits++;
        pow10 *= 10;
        temp /= 10;
    }
    pow10 /= 10;

    while (digits--) {
        chars[size++] = ((len / pow10) % 10) + '0';
        pow10 /= 10;
    }

    return;
}

int compress(vector<char> &chars) {
    if (chars.size() == 1) {
        return 1;
    }

    int size = 0, len = 1, pos = 0;
    for (size_t i = 1; i < chars.size(); i++) {
        if (chars[pos] == chars[i]) {
            len++;
        } else {
            updateVector(chars, size, chars[pos], len);

            pos = i;
            len = 1;
        }
    }
    updateVector(chars, size, chars[pos], len);

    return size;
}
