#include <iostream>
#include <vector>

using namespace std;

#define INT_MAX 2147483647

bool increasingTriplet(vector<int>& nums);

int main() {
    vector<int> nums = {1,5,0,4,1,3};

    cout << "Result: " << increasingTriplet(nums) << endl;

    return 0;
}

bool increasingTriplet(vector<int>& nums) {
    if (nums.size() <= 2) {
        return false;
    }

    int first = nums[0], second = INT_MAX, temp = INT_MAX;

    for (size_t i = 1; i < nums.size(); i++) {
        if (first < second && second < nums[i]) {
            return true;
        }

        if (first < nums[i] && nums[i] < second) {
            second = nums[i];
        }

        if (nums[i] <= first) {
            if (temp < nums[i]) {
                first  = temp;
                second = nums[i];
                temp   = INT_MAX;
            } else {
                temp = nums[i];
            }
        }
    }

    return false;
}
