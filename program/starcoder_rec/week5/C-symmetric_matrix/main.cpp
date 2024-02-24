#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isSymmetric(vector<vector<long>> matrix);

int main() {
    int n, cases = 0;
    cin >> n;

    while (n--) {
        char buffer;
        cin >> buffer >> buffer;

        int size;
        cin >> size;

        vector<vector<long>> matrix(size, vector<long>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> matrix[i][j];
            }
        }

        printf("Test #%d: ", ++cases);
        if (isSymmetric(matrix)) {
            printf("Symmetric.\n");
        } else {
            printf("Non-symmetric.\n");
        }
    }

    return 0;
}

bool isSymmetric(vector<vector<long>> matrix) {
    int n = ((int) matrix.size() + 1) / 2;
    int size = (int) matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[size-1-i][size-1-j] || matrix[i][j] < 0) {
                return false;
            }
        }
    }

    return true;
}
