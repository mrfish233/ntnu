#include <bits/stdc++.h>

using namespace std;

map<int, int> calculate(vector<int> A, vector<int> B, vector<int> C) {
    map<int, int> count;

    int a = (int) A.size();
    int b = (int) B.size();
    int c = (int) C.size();

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                int num = A[i] + B[j] + C[k];

                count[num]++;
            }
        }
    }

    return count;
}

int main() {
    int n;

    cin >> n;
    vector<int> arr1(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> n;
    vector<int> arr2(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    cin >> n;
    vector<int> arr3(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr3[i];
    }

    map<int, int> cal = calculate(arr1, arr2, arr3);

    cin >> n;
    while (n--) {
        int t = 0;
        cin >> t;

        if (cal.count(t) > 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
