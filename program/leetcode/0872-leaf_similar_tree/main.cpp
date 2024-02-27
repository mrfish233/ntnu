#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

// vector<int> leavesOfTree(TreeNode *root);
void leavesOfTree(TreeNode *root, vector<int> &leaves);
bool leafSimilar(TreeNode* root1, TreeNode* root2);

int main() {
    string str1, str2;

    while (cin >> str1 >> str2) {
        TreeNode *root1 = initNodes(str1);
        TreeNode *root2 = initNodes(str2);

        cout << leafSimilar(root1, root2) << endl;
    }

    return 0;
}

void printVector(vector<int> &nums) {
    cout << "[ ";
    for (auto i : nums) {
        cout << i << ' ';
    }
    cout << "]\n";
}

// Recursion, return vector from function

// vector<int> leavesOfTree(TreeNode *root) {
//     vector<int> leaves;

//     if (root == nullptr) {
//         return leaves;
//     }

//     if (root->left == nullptr && root->right == nullptr) {
//         leaves.push_back(root->val);
//     }

//     vector<int> leftLeaves  = leavesOfTree(root->left);
//     vector<int> rightLeaves = leavesOfTree(root->right);

//     leaves.insert(leaves.end(), leftLeaves.begin(),  leftLeaves.end());
//     leaves.insert(leaves.end(), rightLeaves.begin(), rightLeaves.end());

//     return leaves;
// }

// bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//     vector<int> leaves1 = leavesOfTree(root1);
//     vector<int> leaves2 = leavesOfTree(root2);

//     return (leaves1 == leaves2);
// }

// ======================================

// Recursion, return vector from parameters

void leavesOfTree(TreeNode *root, vector<int> &leaves) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        leaves.push_back(root->val);
    }

    leavesOfTree(root->left,  leaves);
    leavesOfTree(root->right, leaves);

    return;
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1, leaves2;

    leavesOfTree(root1, leaves1);
    leavesOfTree(root2, leaves2);

    return (leaves1 == leaves2);
}
