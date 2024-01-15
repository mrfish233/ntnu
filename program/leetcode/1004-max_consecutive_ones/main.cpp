#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int>& nums, int k);

int main() {
    // vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;

    cout << longestOnes(nums, k) << endl;

    return 0;
}

int longestOnes(vector<int>& nums, int k) {
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
        if (zeroes <= k) {
            // Increase window length if zeroes still not more than given k
            len++;
            i--;
        } else if (nums[i] == 0) {
            // Move windows forward, check if first num is zeroes
            zeroes--;
        }
    }

    return len;
}
