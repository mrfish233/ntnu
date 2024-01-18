#include <iostream>
#include <string>

using namespace std;

bool isNicePlate(string plate);

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        string plate;
        cin >> plate;

        if (isNicePlate(plate)) {
            cout << "nice" << endl;
        } else {
            cout << "not nice" << endl;
        }
    }

    return 0;
}

bool isNicePlate(string plate) {
    int letterNum = 0, digitNum = 0;

    for (size_t i = 0; i < 3; i++) {
        letterNum = letterNum * 26 + (plate[i] - 'A');
    }

    for (size_t i = 4; i < plate.length(); i++) {
        digitNum = digitNum * 10 + (plate[i] - '0');
    }

    int check = letterNum - digitNum;

    return (-100 <= check && check <= 100);
}
