#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void printHighestFreq(string str);

int main() {
    string str;

    while (getline(cin, str)) {
        printHighestFreq(str);
    }

    return 0;
}

void printHighestFreq(string str) {
    map<char, int> freq;

    for (char ch : str) {
        if (isalpha(ch)) {
            freq[ch]++;
        }
    }

    // cout << "[ ";
    // for (auto i : freq) {
    //     cout << i.first << ":" << i.second << " ";
    // }
    // cout << " ]\n";

    int highest = 0;

    for (auto it : freq) {
        if (highest < it.second) {
            highest = it.second;
        }
    }

    for (auto it : freq) {
        if (it.second == highest) {
            cout << it.first;
        }
    }
    cout << " " << highest << endl;
}
