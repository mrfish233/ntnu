#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int num);
vector<int> primeCut(int n, int c);

int main() {
    int N, C;

    while (cin >> N >> C) {
        vector<int> cut = primeCut(N, C);

        printf("%d %d:", N, C);
        for (int i = 0; i < cut.size(); i++) {
            printf(" %d", cut[i]);
        }
        printf("\n\n");
    }

    return 0;
}

bool isPrime(int num) {
    if (num == 1 || num == 2) {
        return true;
    } else if (num < 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(num) + 1; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> primeCut(int n, int c) {
    vector<int> prime;

    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }

    // cout << "[ ";
    // for (int i = 0; i < prime.size(); i++) {
    //     cout << prime[i] << " ";
    // }
    // cout << "]\n";

    if (prime.size() <= 2 * c) {
        return prime;
    }

    int x = (prime.size() - (2 * c) + 1) / 2;

    return {prime.begin() + x, prime.end() - x};
}
