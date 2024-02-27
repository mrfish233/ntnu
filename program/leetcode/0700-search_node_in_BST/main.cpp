#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

TreeNode* searchBST(TreeNode* root, int val);

int main() {
    string str;
    int val;

    while (cin >> str >> val) {
        TreeNode *search = searchBST(initNodes(str), val);
        printTree(search);
    }

    return 0;
}

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) {
        return nullptr;
    } else if (root->val == val) {
        return root;
    } else if (root->val < val) {
        return searchBST(root->right, val);
    } else {
        return searchBST(root->left, val);
    }
}
