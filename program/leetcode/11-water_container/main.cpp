#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height);

int main() {
    vector<int> height = {1,2,6,8,5,4,8,3,7};

    cout << "Max area: " << maxArea(height) << endl;

    return 0;
}

int maxArea(vector<int> &height) {
    // O(n^2) time complexity

    // int area = 0, temp = 0;

    // for (size_t i = 0; i < height.size(); i++) {
    //     for (size_t j = i + 1; j < height.size(); j++) {
    //         temp = (j - i) * min(height[i], height[j]);
    //         area = max(temp, area);
    //     }
    // }

    // return area;

    // ====================

    // O(n) time complexity

    int area = 0, temp = 0;
    size_t head = 0, tail = height.size() - 1;

    while (head < tail) {
        temp = int(tail - head) * min(height[head], height[tail]);
        area = max(temp, area);

        if (height[head] < height[tail]) {
            head++;
        } else {
            tail--;
        }
    }

    return area;
}
