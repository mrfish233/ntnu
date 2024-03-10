#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> board, string move) {
    
}

int main() {
    vector<string> board(5);
    string move;

    int cases = 0;

    while (getline(cin, board[0])) {
        for (int i = 1; i < 5; i++) {
            cin >> board[i];
        }

        cin >> move;

        printf("Puzzle #%d:\n", ++cases);
    }

    return 0;
}


