#include <iostream>
#include <string>
#include <queue>

using namespace std;

string predictPartyVictory(string senate);

int main() {
    string senate;

    while (cin >> senate) {
        cout << predictPartyVictory(senate) << endl;
    }

    return 0;
}

size_t updateIndex(size_t i, size_t max) {
    if (i == max) {
        return 0;
    }

    return i + 1;
}

string predictPartyVictory(string senate) {
    // Solution without queue

    // size_t i = 0, j = 1, maxIndex = senate.length() - 1;

    // while (true) {
    //     if (senate[i] == 'X') {
    //         i = updateIndex(i, maxIndex);
    //         continue;
    //     }

    //     j = updateIndex(i, maxIndex);

    //     while (j != i) {
    //         if (senate[j] != 'X' && senate[j] != senate[i]) {
    //             senate[j] = 'X';
    //             break;
    //         }

    //         j = updateIndex(j, maxIndex);
    //     }

    //     if (j == i) {
    //         break;
    //     }

    //     i = updateIndex(i, maxIndex);
    // }

    // return (senate[i] == 'R') ? "Radiant" : "Dire";

    // ===========================

    // Solution with one queue

    // queue<char> senators;

    // for (size_t i = 0; i < senate.length(); i++) {
    //     if (senators.empty() || senate[i] == senators.front()) {
    //         senators.push(senate[i]);
    //     } else {
    //         senate += senators.front();
    //         senators.pop();
    //     }
    // }

    // return (senators.front() == 'R') ? "Radiant" : "Dire";

    // ===========================

    // Solution with 2 queues

    queue<int> rad, dir;
    size_t i = 0;

    for (i = 0; i < senate.length(); i++) {
        if (senate[i] == 'R') {
            rad.push(i);
        } else {
            dir.push(i);
        }
    }

    while (!rad.empty() && !dir.empty()) {
        if (rad.front() < dir.front()) {
            rad.push(i++);
        } else {
            dir.push(i++);
        }

        rad.pop();
        dir.pop();
    }

    return (!rad.empty()) ? "Radiant" : "Dire";
}
