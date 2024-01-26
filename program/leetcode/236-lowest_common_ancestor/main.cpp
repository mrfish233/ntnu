#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

TreeNode *findNode(TreeNode *root, int val);
TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

int main() {
    string str;
    int p, q;

    while (cin >> str >> p >> q) {
        TreeNode *root  = initNodes(str);
        TreeNode *node1 = findNode(root, p);
        TreeNode *node2 = findNode(root, q);

        TreeNode *ancestor = lowestCommonAncestor(root, node1, node2);

        cout << ancestor->val << endl;
    }

    return 0;
}

TreeNode *findNode(TreeNode *root, int val) {
    if (!root) {
        return nullptr;
    } else if (root->val == val) {
        return root;
    }

    TreeNode *left  = findNode(root->left,  val);
    TreeNode *right = findNode(root->right, val);

    return (left) ? left : (right) ? right : nullptr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode *left  = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    return (left && right) ? root : (left) ? left : right;
}
