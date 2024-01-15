#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

const bool LEFT  = false;
const bool RIGHT = true;

int longestZigZag(TreeNode* root);
int longestZigZag(TreeNode* root, bool dir);

int main() {
    string str;

    while (cin >> str) {
        // vector<string> treeNodes = stringToVector(str);
        TreeNode *root = initNodes(stringToVector(str));

        cout << longestZigZag(root) << endl;
    }

    return 0;
}

int longestZigZag(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftZigZag  = longestZigZag(root, LEFT);
    int rightZigZag = longestZigZag(root, RIGHT);

    return max(leftZigZag, rightZigZag) + 1;
}

int longestZigZag(TreeNode* root, bool dir) {
    if (!root) {
        return 0;
    }

    int left  = longestZigZag(root->left, RIGHT);
    int right = longestZigZag(root->right, LEFT);

    if (root->left && dir == LEFT) {
        left++;
    }

    if (root->right && dir == RIGHT) {
        right++;
    }

    return max(left, right);
}
