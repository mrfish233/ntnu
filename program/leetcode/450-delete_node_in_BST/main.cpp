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
    if (!root) {
        return nullptr;
    } else if (!root->left && !root->right) {
        if (root->val == key) {
            delete root;
            root = nullptr;
        }

        return root;
    }

    // Find node to be deleted

    TreeNode *curr  = root;
    TreeNode *pCurr = nullptr;

    while (curr && curr->val != key) {

        pCurr = curr;
        if (curr->val < key) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    if (!curr) {
        return root;
    }

    // Find node to be replaced to deleted node

    TreeNode *temp  = curr;
    TreeNode *pTemp = pCurr;

    if (temp->right) {
        pTemp = temp;
        temp  = temp->right;

        while (temp->left) {
            pTemp = temp;
            temp  = temp->left;
        }

        while (temp->right) {
            pTemp = temp;
            temp  = temp->right;
            swap(pTemp->val, temp->val);
        }
    } else if (temp->left) {
        pTemp = temp;
        temp  = temp->left;

        while (temp->right) {
            pTemp = temp;
            temp  = temp->right;
        }

        while (temp->left) {
            pTemp = temp;
            temp  = temp->left;
            swap(pTemp->val, temp->val);
        }
    }

    // printf("curr: %d, pCurr: %d\n", curr->val, pCurr ? pCurr->val : -1);
    // printf("temp: %d, pTemp: %d\n", temp->val, pTemp ? pTemp->val : -1);

    // Replace and delete node

    curr->val = temp->val;

    if (pTemp->left == temp) {
        pTemp->left = nullptr;
    } else {
        pTemp->right = nullptr;
    }

    delete temp;

    return root;
}
