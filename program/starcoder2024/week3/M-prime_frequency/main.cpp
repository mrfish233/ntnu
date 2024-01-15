#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num);
string primeFrequency(string str);

int main() {
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;

        cout << "Case " << i << ": " << primeFrequency(str) << endl;
    }

    return 0;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i < (int) sqrt(num) + 1; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

string primeFrequency(string str) {
    vector<int> freq(123, 0);

    for (auto ch : str) {
        freq[ch]++;
    }

    string result;

    for (char c = '0'; c <= '9'; c++) {
        if (isPrime(freq[c])) {
            result += c;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (isPrime(freq[c])) {
            result += c;
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (isPrime(freq[c])) {
            result += c;
        }
    }

    if (result.empty()) {
        return "empty";
    }

    return result;
}
