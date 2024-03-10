#include <iostream>
#include <vector>

using namespace std;

int fastThree(vector<int> nums);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << fastThree(nums) << "\n";
    }

    return 0;
}

int fastThree(vector<int> nums) {
    int n = (int) nums.size();
    int sum = 0;
    int mod1 = 0;

    for (int i = 0; i < n; i++) {
        int num = nums[i] % 3;

        if (num == 1) {
            mod1++;
        }

        sum += num;
    }

    int result = sum % 3;

    if (result == 0) {
        return 0;
    } else if ((result == 1 && mod1) || result == 2) {
        return 1;
    } else {
        return 2;
    }
}
