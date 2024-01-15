#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums);

void printVector(vector<int> &nums) {
    for (auto i : nums) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> nums = {0,1,0,3,12,5,6,3,0,0,3,4,1,5,0};

    printVector(nums);
    moveZeroes(nums);
    printVector(nums);

    return 0;
}

void moveZeroes(vector<int>& nums) {
    size_t dist = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        // Add dist approach

        // if (nums[i] != 0) {
        //     continue;
        // }

        // while (i + dist < nums.size() && nums[i + dist] == 0) {
        //     dist++;
        // }

        // if (i + dist < nums.size()) {
        //     swap(nums[i], nums[i + dist]);
        // } else {
        //     break;
        // }

        // ======================

        // Minus dist approach

        if (nums[i] == 0) {
            dist++;
        } else if (dist > 0) {
            swap(nums[i], nums[i - dist]);
        }
    }

    return;
}
