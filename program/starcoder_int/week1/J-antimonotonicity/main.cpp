#include <iostream>
#include <vector>
using namespace std;

#define SEQ 0
#define NUM 1
#define FLAG 2

int longestSequence(vector<int> nums);

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        int size;
        cin >> size;

        vector<int> nums(size, 0);
        for (int i = 0; i < (int) nums.size(); i++) {
            cin >> nums[i];
        }

        cout << longestSequence(nums) << endl;
    }

    return 0;
}

int longestSequence(vector<int> nums) {
    if (nums.empty()) {
        return 0;
    }

    int seq = 1, flag = 0;

    for (int i = 1; i < (int) nums.size(); i++) {
        if ((nums[i-1] > nums[i] && flag == 0) ||
            (nums[i-1] < nums[i] && flag == 1)) {
            seq++;
            flag = !flag;
        }
    }

    return seq;
}
