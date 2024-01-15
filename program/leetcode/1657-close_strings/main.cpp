#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool closeStrings(string word1, string word2);

int main() {
    // string word1 = "abc", word2 = "bca";
    // string word1 = "a", word2 = "aa";
    // string word1 = "cabbba", word2 = "abbccc";
    // string word1 = "cabbbaa", word2 = "abbcccd";
    string word1 = "cabbbaa", word2 = "abbcccc";

    cout << closeStrings(word1, word2) << endl;

    return 0;
}

bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length()) {
        return false;
    }

    map<char, int> map1, map2;
    vector<int> count1, count2;

    // Map words

    for (auto ch : word1) {
        map1[ch]++;
    }

    for (auto ch : word2) {
        map2[ch]++;
    }

    // Check if characters in first word appears in second word.
    // No need to check second word, as it will be different in
    // vectors and thus return false.

    for (auto [ch, num] : map1) {
        if (map2[ch] == 0) {
            return false;
        }

        // Push number of each characters to array

        count1.push_back(num);
        count2.push_back(map2[ch]);
    }

    // Sort array

    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());

    // Check if array is same

    return (count1 == count2);
}
