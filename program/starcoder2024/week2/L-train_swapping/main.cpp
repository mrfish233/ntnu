#include <iostream>
#include <vector>

using namespace std;

int optimalSwap(vector<int> nums);

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        int length = 0, num = 0;
        cin >> length;

        vector<int> nums;
        while (length--) {
            cin >> num;
            nums.push_back(num);
        }

        cout << "Optimal train swapping takes " << optimalSwap(nums) << " swaps." << endl;
    }

    return 0;
}

int optimalSwap(vector<int> nums) {
    int count = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        for (size_t j = 0; j < nums.size() - i - 1; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                count++;
            }
        }
    }

    return count;
}
