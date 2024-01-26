#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

int goodNodes(TreeNode* root);
int goodNodes(TreeNode* root, int compare);

int main() {
    string str;

    while (cin >> str) {
        TreeNode *root = initNodes(str);

        cout << goodNodes(root) << endl;
    }

    return 0;
}

int goodNodes(TreeNode* root) {
    return goodNodes(root, INT32_MIN);
}

int goodNodes(TreeNode* root, int compare) {
    if (root == nullptr) {
        return 0;
    }

    int total = 0;

    if (compare <= root->val) {
        compare = root->val;
        total += 1;
    }

    total += goodNodes(root->left, compare);
    total += goodNodes(root->right, compare);

    return total;
}
