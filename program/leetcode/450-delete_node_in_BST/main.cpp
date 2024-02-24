#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

TreeNode *deleteNode(TreeNode* root, int key);

int main() {
    string str;
    int key;

    while (cin >> str >> key) {
        TreeNode *root = initNodes(str);
        printTree(root);
        TreeNode *del  = deleteNode(root, key);
        printTree(del);
    }

    return 0;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    TreeNode *curr = root, *prev = nullptr;

    while (curr != nullptr) {
        if (curr->val == key) {
            break;
        }

        prev = curr;

        if (curr->val < key) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    if (curr == nullptr) {
        return root;
    }

    if (curr->left == nullptr || curr->right == nullptr) { // 0 or 1 child node
        TreeNode *next = (curr->left) ? curr->left : curr->right;

        if (curr == root) {
            root = next;
        } else if (curr == prev->left) {
            prev->left = next;
        } else {
            prev->right = next;
        }

        delete curr;
    } else { // 2 child nodes
        TreeNode *temp = curr->right;

        while (temp->left) {
            temp = temp->left;
        }

        int tempVal = temp->val;

        // Recursive delete node
        root = deleteNode(root, tempVal);

        curr->val = tempVal;
    }

    return root;
}
