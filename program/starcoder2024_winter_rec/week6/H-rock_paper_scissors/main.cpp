#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define WIN  0
#define LOSE 1
#define TIE  2

#define R 1
#define P 2
#define S 3

void processRound(int p1, string s1, int p2, string s2, vector<vector<int>> &stat);
void printWinRate(vector<vector<int>> stat);

int main() {
    int n, print = 0;

    while (cin >> n && n) {
        int k;
        cin >> k;

        vector<vector<int>> stat(n, vector<int>(3, 0));

        int round = k * n * (n-1) / 2;

        for (int j = 0; j < round; j++) {
            int p1, p2;
            string s1, s2;
            cin >> p1 >> s1 >> p2 >> s2;

            processRound(p1, s1, p2, s2, stat);
        }

        if (print) {
            printf("\n");
        }
        print = 1;

        printWinRate(stat);
    }

    return 0;
}

void processRound(int p1, string s1, int p2, string s2, vector<vector<int>> &stat) {
    int res1, res2;

    if (s1[0] == s2[0]) {
        res1 = TIE;
        res2 = TIE;
    } else if ((s1[0] == 'r' && s2[0] == 's') ||
               (s1[0] == 's' && s2[0] == 'p') ||
               (s1[0] == 'p' && s2[0] == 'r')) {
        res1 = WIN;
        res2 = LOSE;
    } else {
        res1 = LOSE;
        res2 = WIN;
    }

    stat[p1-1][res1]++;
    stat[p2-1][res2]++;
}

void printWinRate(vector<vector<int>> stat) {
    for (int i = 0; i < stat.size(); i++) {
        int win = stat[i][WIN];
        int ttl = stat[i][WIN] + stat[i][LOSE];

        if (ttl == 0) {
            printf("-\n");
        } else {
            printf("%.3f\n", (double) win / ttl);
        }
    }
}
