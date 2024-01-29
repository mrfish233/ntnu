#include <iostream>
#include <vector>
#include <string>
using namespace std;

string findSlogan(vector<string> first, vector<string> second, string slogan);

int main() {
    int n;
    string slogan;
    vector<string> first, second;

    cin >> n;
    cin.ignore();

    while (n--) {
        getline(cin, slogan);
        first.push_back(slogan);

        getline(cin, slogan);
        second.push_back(slogan);
    }

    cin >> n;
    cin.ignore();

    while (n--) {
        getline(cin, slogan);
        cout << findSlogan(first, second, slogan) << endl;
    }

    return 0;
}

string findSlogan(vector<string> first, vector<string> second, string slogan) {
    string result;

    for (int i = 0; i < (int) first.size(); i++) {
        if (first[i] == slogan) {
            result = second[i];
            break;
        }
    }

    return result;
}
