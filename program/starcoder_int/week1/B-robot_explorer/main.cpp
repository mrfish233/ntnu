#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define X 0
#define Y 1
#define ORI 2

int moveRobot(vector<int> &pos, vector<int> maxPos, string ins, vector<vector<int>> &scents);

int main() {
    vector<int> maxPos(2, 0);
    cin >> maxPos[X] >> maxPos[Y];

    vector<int> pos(3, 0);
    vector<vector<int>> scents;

    int x, y;
    char ori;

    while (cin >> x >> y >> ori) {
        string ins;
        cin >> ins;

        pos[X] = x;
        pos[Y] = y;
        pos[ORI] = ori;

        int move = moveRobot(pos, maxPos, ins, scents);

        cout << pos[X] << " " << pos[Y] << " " << (char) pos[ORI];

        if (move == 0) {
            cout << " LOST";
        }

        cout << endl;
    }

    return 0;
}

char changeOrientation(char ori, char turn) {
    if (turn == 'L') {
        if (ori == 'N') {
            ori = 'W';
        } else if (ori == 'W') {
            ori = 'S';
        } else if (ori == 'S') {
            ori = 'E';
        } else if (ori == 'E') {
            ori = 'N';
        }
    } else {
        if (ori == 'N') {
            ori = 'E';
        } else if (ori == 'E') {
            ori = 'S';
        } else if (ori == 'S') {
            ori = 'W';
        } else if (ori == 'W') {
            ori = 'N';
        }
    }

    return ori;
}

int moveForward(vector<int> &pos, vector<int> maxPos, vector<vector<int>> &scents) {
    for (auto scent : scents) {
        if (pos == scent) {
            return 1;
        }
    }

    if ((pos[ORI] == 'E' && pos[X] == maxPos[X]) || (pos[ORI] == 'W' && pos[X] == 0)) {
        scents.push_back({ pos[X], pos[Y], pos[ORI] });

        if (pos[Y] == maxPos[Y]) {
            scents.push_back({ pos[X], pos[Y], 'N' });
        } else if (pos[Y] == 0) {
            scents.push_back({ pos[X], pos[Y], 'S' });
        }

        return 0;
    }

    if ((pos[ORI] == 'N' && pos[Y] == maxPos[Y]) || (pos[ORI] == 'S' && pos[X] == 0)) {
        scents.push_back({ pos[X], pos[Y], pos[ORI] });

        if (pos[X] == maxPos[X]) {
            scents.push_back({ pos[X], pos[Y], 'E' });
        } else if (pos[X] == 0) {
            scents.push_back({ pos[X], pos[Y], 'W' });
        }

        return 0;
    }

    if (pos[ORI] == 'E') {
        pos[X]++;
    } else if (pos[ORI] == 'W') {
        pos[X]--;
    } else if (pos[ORI] == 'N') {
        pos[Y]++;
    } else if (pos[ORI] == 'S') {
        pos[Y]--;
    }

    return 1;
}

int moveRobot(vector<int> &pos, vector<int> maxPos, string ins, vector<vector<int>> &scents) {
    for (size_t i = 0; i < ins.length(); i++) {
        if (ins[i] == 'L' || ins[i] == 'R') {
            pos[ORI] = changeOrientation(pos[ORI], ins[i]);
        } else if (moveForward(pos, maxPos, scents) == 0) {
            return 0;
        }
    }

    return 1;
}
