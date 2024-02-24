#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<vector<int>> press = {
    {0,1,1,1,0,0,1,1,1,1},  // c
    {0,1,1,1,0,0,1,1,1,0},  // d
    {0,1,1,1,0,0,1,1,0,0},  // e
    {0,1,1,1,0,0,1,0,0,0},  // f
    {0,1,1,1,0,0,0,0,0,0},  // g
    {0,1,1,0,0,0,0,0,0,0},  // a
    {0,1,0,0,0,0,0,0,0,0},  // b
    {0,0,1,0,0,0,0,0,0,0},  // C
    {1,1,1,1,0,0,1,1,1,0},  // D
    {1,1,1,1,0,0,1,1,0,0},  // E
    {1,1,1,1,0,0,1,0,0,0},  // F
    {1,1,1,1,0,0,0,0,0,0},  // G
    {1,1,1,0,0,0,0,0,0,0},  // A
    {1,1,0,0,0,0,0,0,0,0},  // B
};

int noteIndex(char ch);
vector<int> countPressed(string str);

int main() {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string str;
        getline(cin, str);

        vector<int> finger = countPressed(str);

        for (int i = 0; i < finger.size(); i++) {
            if (i != 0) {
                cout << " ";
            }

            cout << finger[i];
        }
        cout << endl;
    }

    return 0;
}

int noteIndex(char ch) {
    switch(ch) {
        case 'c': return  0; break;
        case 'd': return  1; break;
        case 'e': return  2; break;
        case 'f': return  3; break;
        case 'g': return  4; break;
        case 'a': return  5; break;
        case 'b': return  6; break;
        case 'C': return  7; break;
        case 'D': return  8; break;
        case 'E': return  9; break;
        case 'F': return 10; break;
        case 'G': return 11; break;
        case 'A': return 12; break;
        case 'B': return 13; break;
        default: return -1; break;
    }
}

vector<int> countPressed(string str) {
    vector<int> finger(10, 0);

    if (str.empty()) {
        return finger;
    }

    for (int i = 0; i < (int) finger.size(); i++) {
        int note  = noteIndex(str[0]);
        finger[i] = press[note][i];
    }

    for (int i = 1; i < (int) str.size(); i++) {
        int last = noteIndex(str[i-1]);
        int curr = noteIndex(str[i]);

        for (int j = 0; j < (int) finger.size(); j++) {
            if (press[last][j] == 0 && press[curr][j] == 1) {
                finger[j]++;
            }
        }
    }

    return finger;
}
