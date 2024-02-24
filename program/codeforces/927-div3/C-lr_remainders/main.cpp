#include <iostream>
#include <vector>

using namespace std;

void printRemainder(vector<int> nums, string str, int m);

int main() {
    int k;
    cin >> k;

    while (k--) {
        int n, m;
        cin >> n >> m;

        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        string str;
        cin >> str;

        printRemainder(nums, str, m);
        cout << endl;
    }

    return 0;
}

void printRemainder(vector<int> nums, string str, int m) {
    int i = 0, head = 0, tail = nums.size();

    while (head != tail) {
        int res = 1;
        for (int j = head; j < tail; j++) {
            res = (res * nums[j]) % m; 
        }

        cout << res;
        if (nums.size() != 1) {
            cout << " ";
        }

        if (str[i++] == 'L') {
            head++;
        } else {
            tail--;
        }
    }
}
