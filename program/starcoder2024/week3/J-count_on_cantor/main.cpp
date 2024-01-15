#include <iostream>

using namespace std;

string cantor(int num);

int main() {
    int num;

    while (cin >> num) {
        cout << "TERM " << num << " IS " << cantor(num) << endl;
    }

    return 0;
}

string cantor(int num) {
    int line = 0, sum = 0;

    while (num > sum) {
        sum += (++line);
    }

    int a = sum - num + 1;
    int b = (line + 1) - a;

    if (line % 2 == 0) {
        swap(a, b);
    }

    return to_string(a) + "/" + to_string(b);
}
