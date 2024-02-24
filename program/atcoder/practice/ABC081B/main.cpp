#include <iostream>
#include <vector>

using namespace std;

int operation(int num);
int maxOperation(vector<int> nums);

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << maxOperation(nums) << endl;
    }

    return 0;
}

int operation(int num) {
    int op = 0;

    while (num % 2 == 0) {
        num /= 2;
        op++;
    }

    return op;
}

int maxOperation(vector<int> nums) {
    int op = INT32_MAX, size = (int) nums.size();

    for (int i = 0; i < size; i++) {
        int tmp = operation(nums[i]);
        op = min(op, tmp);
    }

    if (op == INT32_MAX) {
        return 0;
    }

    return op;
}

