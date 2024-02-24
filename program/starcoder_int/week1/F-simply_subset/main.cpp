#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> initSet(string str);
void compareSet(set<int> a, set<int> b);

int main() {
    string strA, strB;

    while (getline(cin, strA), getline(cin, strB)) {
        set<int> a = initSet(strA);
        set<int> b = initSet(strB);

        compareSet(a, b);
    }

    return 0;
}

set<int> initSet(string str) {
    set<int> myset;
    string temp;

    for (auto ch : str) {
        if (isdigit(ch)) {
            temp += ch;
        } else {
            myset.insert(stoi(temp));
            temp.clear();
        }
    }

    if (!temp.empty()) {
        myset.insert(stoi(temp));
    }

    return myset;
}

void compareSet(set<int> a, set<int> b) {
    if (a.empty() || b.empty()) {
        if (a.empty() && b.empty()) {
            cout << "A equals B\n";
        } else if (a.empty()) {
            cout << "A is a proper subset of B\n";
        } else if (b.empty()) {
            cout << "B is a proper subset of A\n";
        }

        return;
    }

    if (a.empty() && !b.empty()) {
        cout << "A is a proper subset of B\n";
        return;
    } else if (b.empty() && !a.empty()) {
        cout << "B is a proper subset of A\n";
        return;
    }

    bool sameFlag = false, flagA = false, flagB = false;

    auto i = a.begin(), j = b.begin();
    while (i != a.end() && j != b.end()) {
        if (*i == *j) {
            sameFlag = true;
            i++; j++;
        } else if (*i < *j) {
            flagA = true;
            i++;
        } else if (*i > *j) {
            flagB = true;
            j++;
        }
    }

    if (i != a.end()) {
        flagA = true;
    }

    if (j != b.end()) {
        flagB = true;
    }

    if (!sameFlag) {
        cout << "A and B are disjoint\n";
    } else if (!flagA && !flagB) {
        cout << "A equals B\n";
    } else if (flagA && flagB) {
        cout << "I'm confused!\n";
    } else if (flagA) {
        cout << "B is a proper subset of A\n";
    } else if (flagB) {
        cout << "A is a proper subset of B\n";
    }
}
