#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b);
void printSorted(map<char, int> lang);
bool newState(vector<string> world, vector<vector<bool>> &check, char ch, int x, int y);

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        int h, w;
        cin >> h >> w;

        vector<string> world;
        vector<vector<bool>> check(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++) {
            string str;
            cin >> str;

            world.push_back(str);
        }

        map<char, int> lang;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (newState(world, check, world[i][j], i, j)) {
                    lang[world[i][j]]++;
                }
            }
        }

        cout << "World #" << k << endl;
        printSorted(lang);
    }

    return 0;
}

bool cmp(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

void printSorted(map<char, int> lang) {
    vector<pair<char, int>> vect;

    for (auto i : lang) {
        vect.push_back(i);
    }

    sort(vect.begin(), vect.end(), [](pair<char, int> &a, pair<char, int> &b) -> bool {
        return a.second > b.second;
    });

    for (auto it : vect) {
        cout << it.first << ": " << it.second << endl;
    }
}

bool newState(vector<string> world, vector<vector<bool>> &check, char ch, int x, int y) {
    if (x < 0 || x == (int) check.size() || y < 0 || y == (int) check[0].size()) {
        return false;
    }

    if (check[x][y] || ch != world[x][y]) {
        return false;
    }

    check[x][y] = true;

    newState(world, check, ch, x+1, y);
    newState(world, check, ch, x-1, y);
    newState(world, check, ch, x, y+1);
    newState(world, check, ch, x, y-1);

    return true;
}
