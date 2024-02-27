#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

int maxDepth(TreeNode* root);
// int maxDepth(TreeNode* root, int depth);

int main() {
    string str;

    while (cin >> str) {
        TreeNode *root = initNodes(str);

        cout << "Max depth: " << maxDepth(root) << endl;
    }

    return 0;
}

// Recursion 1

// int maxDepth(TreeNode* root) {
//     return maxDepth(root, 1);
// }

// int maxDepth(TreeNode* root, int depth) {
//     if (root == nullptr) {
//         return depth - 1;
//     }

//     int maxLeft  = maxDepth(root->left,  depth + 1);
//     int mexRight = maxDepth(root->right, depth + 1);

//     return max(maxLeft, mexRight);
// }

// =================================

// Recursion 2

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int maxLeft  = maxDepth(root->left);
    int maxRight = maxDepth(root->right);

    return max(maxLeft, maxRight) + 1;
}
