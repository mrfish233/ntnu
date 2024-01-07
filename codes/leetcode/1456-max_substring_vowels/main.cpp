#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch);
int maxVowels(string s, int k);

int main() {
    string s = "leetcode";
    int k = 3;

    cout << maxVowels(s, k) << endl;

    return 0;
}

bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int maxVowels(string s, int k) {
    int currMax = 0;

    for (size_t i = 0; i < (size_t) k; i++) {
        if (isVowel(s[i])) {
            currMax++;
        }
    }

    if (currMax == k) {
        return currMax;
    }

    int tempMax = currMax;
    for (size_t i = k; i < s.length(); i++) {
        tempMax += isVowel(s[i]) - isVowel(s[i-k]);
        currMax  = max(tempMax, currMax);

        if (currMax == k) {
            return currMax;
        }
    }

    return currMax;
}
