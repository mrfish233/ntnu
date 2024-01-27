#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

int maxLevelSum(TreeNode* root);
// vector<int> levelSum(TreeNode* root);
void levelSum(TreeNode *root, vector<int> &sum, int level);

int main() {
    string str;

    while (cin >> str) {
        // TreeNode *root = initNodes(str);
        cout << maxLevelSum(initNodes(str)) << endl;
    }

    return 0;
}

// Solution 1

// vector<int> levelSum(TreeNode* root) {
//     if (!root) {
//         return {};
//     }

//     vector<int> sum = { root->val };

//     vector<int> left  = levelSum(root->left);
//     vector<int> right = levelSum(root->right);

//     if (left.size() > right.size()) {
//         sum.insert(sum.end(), left.begin(), left.end());

//         for (size_t i = 0; i < right.size(); i++) {
//             sum[i+1] += right[i];
//         }
//     } else {
//         sum.insert(sum.end(), right.begin(), right.end());

//         for (size_t i = 0; i < left.size(); i++) {
//             sum[i+1] += left[i];
//         }
//     }

//     return sum;
// }

// ================================

// Solution 2

void levelSum(TreeNode *root, vector<int> &sum, int level) {
    if (!root) {
        return;
    }

    if ((int) sum.size() == level) {
        sum.push_back(root->val);
    } else {
        sum[level] += root->val;
    }

    levelSum(root->left,  sum, level + 1);
    levelSum(root->right, sum, level + 1);
}

int maxLevelSum(TreeNode* root) {
    // Solution 1

    // vector<int> sum = levelSum(root);

    // int max = 0;
    // for (size_t i = 0; i < sum.size(); i++) {
    //     if (sum[max] < sum[i]) {
    //         max = i;
    //     }
    // }

    // return max + 1;

    // ============================

    // Solution 2

    vector<int> sum = {};

    levelSum(root, sum, 0);

    // cout << "[ ";
    // for (int i : sum) {
    //     cout << i << " ";
    // }
    // cout << "]\n";

    return max_element(sum.begin(), sum.end()) - sum.begin() + 1;
}
