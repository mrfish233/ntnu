#include <iostream>
#include <vector>

using namespace std;

int luhnDigit(int digit);
bool isValidCard(vector<int> nums);

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        vector<int> nums(4, 0);

        for (int i = 0; i < 4; i++) {
            cin >> nums[i];
        }

        if (isValidCard(nums)) {
            cout << "Valid" << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}

int luhnDigit(int digit) {
    if (digit <= 4) {
        return digit * 2;
    } else {
        return (digit - 5) * 2 + 1;
    }
}

bool isValidCard(vector<int> nums) {
    int total = 0;

    for (int i = 0; i < 4; i++) {
        bool check = false;
        while (nums[i] > 0) {
            if (check) {
                total += luhnDigit(nums[i] % 10);
                check  = false;
            } else {
                total += nums[i] % 10;
                check  = true;
            }

            nums[i] /= 10;
        }
    }

    return (total % 10 == 0);
}
