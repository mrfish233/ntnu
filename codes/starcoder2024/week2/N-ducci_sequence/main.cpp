#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isDucciLoop(vector<int> nums);

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        vector<int> nums;
        int size = 0, num = 0;

        cin >> size;
        while (size--) {
            cin >> num;
            nums.push_back(num);
        }

        if (isDucciLoop(nums)) {
            cout << "LOOP" << endl;
        } else {
            cout << "ZERO" << endl;
        }
    }

    return 0;
}

bool isDucciLoop(vector<int> nums) {
    int loop = 0;

    while (loop <= 1000) {
        int zero = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                break;
            }

            zero++;
        }

        if (zero == (int) nums.size()) {
            return false;
        }

        int temp = nums[0];
        for (size_t i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                nums[i] = abs(nums[i] - temp);
            } else {
                nums[i] = abs(nums[i] - nums[i+1]);
            }
        }

        loop++;
    }

    return true;
}
