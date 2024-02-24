#include <iostream>
#include <cstring>
using namespace std;

#define N 100
#define L 120

const char output[][20] = {"Accepted", "Presentation Error", "Wrong Answer"};

bool isAC(char ans[][L+1], int ansSize, char out[][L+1], int outSize);
bool isPE(char ans[][L+1], int ansSize, char out[][L+1], int outSize);
int judge(char ans[][L+1], int ansSize, char out[][L+1], int outSize);

int main() {
    int n = 0, m = 0, cases = 0;
    char ans[N][L+1], out[N][L+1];

    while (cin >> n && n != 0) {
        getchar();
        for (int i = 0; i < n; i++) {
            fgets(ans[i], L, stdin);
        }

        cin >> m;
        getchar();
        for (int i = 0; i < m; i++) {
            fgets(out[i], L, stdin);
        }

        int res = judge(ans, n, out, m);
        printf("Run #%d: %s\n", ++cases, output[res]);
    }

    return 0;
}

bool isAC(char ans[][L+1], int ansSize, char out[][L+1], int outSize) {
    if (ansSize != outSize) {
        return false;
    }

    for (int i = 0; i < ansSize; i++) {
        if (strcmp(ans[i], out[i])) {
            return false;
        }
    }

    return true;
}

bool isPE(char ans[][L+1], int ansSize, char out[][L+1], int outSize) {
    char ansNum[N * L + 1], outNum[N * L + 1];
    int x = 0, y = 0;

    for (int i = 0; i < ansSize; i++) {
        for (int j = 0; ans[i][j] != '\n'; j++) {
            if (isdigit(ans[i][j])) {
                ansNum[x++] = ans[i][j];
            }
        }
    }

    for (int i = 0; i < outSize; i++) {
        for (int j = 0; out[i][j] != '\n'; j++) {
            if (isdigit(out[i][j])) {
                outNum[y++] = out[i][j];
            }
        }
    }

    ansNum[x] = '\0';
    outNum[y] = '\0';

    return (strcmp(ansNum, outNum) == 0);
}

int judge(char ans[][L+1], int ansSize, char out[][L+1], int outSize) {
    if (isAC(ans, ansSize, out, outSize)) {
        return 0;
    } else if (isPE(ans, ansSize, out, outSize)) {
        return 1;
    } else {
        return 2;
    }
}
