// This question is similar to 1004.

#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int>& nums);

int main() {
    // vector<int> nums = {1,1,0,1};
    // vector<int> nums = {0,1,1,1,0,1,1,0,1};
    vector<int> nums = {1,1,1};

    cout << longestSubarray(nums) << endl;

    return 0;
}

int longestSubarray(vector<int>& nums) {
    int len = 0, zeroes = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        // If i+len reaches the end of vectors
        if (i + len >= nums.size()) {
            break;
        }

        // Check if the last num is 0
        if (nums[i + len] == 0) {
            zeroes++;
        }

        // Check the number of zeroes
        if (zeroes <= 1) {
            // Increase window length if zeroes still not more than given k
            len++;
            i--;
        } else if (nums[i] == 0) {
            // Move windows forward, check if first num is zeroes
            zeroes--;
        }
    }

    return len - 1;
}
