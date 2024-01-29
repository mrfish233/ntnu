#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool isCoolWord(string str);

int main() {
    int n, cases = 0;
    string str;

    while (cin >> n) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            cin >> str;
            if (isCoolWord(str)) {
                count++;
            }
        }

        printf("Case %d: %d\n", ++cases, count);
    }

    return 0;
}

bool isCoolWord(string str) {
    map<char, int> charCount;

    for (char ch : str) {
        charCount[ch]++;
    }

    if (charCount.size() <= 1) {
        return false;
    }

    vector<int> count;

    for (auto it : charCount) {
        count.push_back(it.second);
    }

    for (int i = 0; i < (int) count.size(); i++) {
        for (int j = i+1; j < (int) count.size(); j++) {
            if (count[i] == count[j]) {
                return false;
            }
        }
    }

    return true;
}
