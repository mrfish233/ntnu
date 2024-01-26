#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

const bool LEFT  = false;
const bool RIGHT = true;

int longestZigZag(TreeNode* root);
int longestZigZag(TreeNode* root, bool dir, int depth);

int main() {
    string str;

    while (cin >> str) {
        TreeNode *root = initNodes(str);

        printTree(root);

        cout << longestZigZag(root) << endl;
    }

    return 0;
}

int longestZigZag(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left  = longestZigZag(root->left,  LEFT,  0);
    int right = longestZigZag(root->right, RIGHT, 0);

    return max(left, right);
}

int longestZigZag(TreeNode* root, bool dir, int len) {
    if (!root) {
        return len;
    }

    int left = 0, right = 0;

    if (dir == LEFT) {
        left  = longestZigZag(root->left,  LEFT,  0);
        right = longestZigZag(root->right, RIGHT, len + 1);
    } else {
        left  = longestZigZag(root->left,  LEFT,  len + 1);
        right = longestZigZag(root->right, RIGHT, 0);
    }

    return max(left, right);
}
