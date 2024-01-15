#include <iostream>
// #include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

int pathSum(TreeNode* root, int targetSum);
int pathSum(TreeNode* root, int targetSum, vector<long> &target);

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) { 
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

int main() {
    string target, str;

    while (cin >> target >> str) {
        vector<string> treeNodes = stringToVector(str);
        TreeNode *root = initNodes(treeNodes);

        printTree(root);

        cout << pathSum(root, stoi(target)) << endl;
    }

    return 0;
}

int pathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return 0;
    }

    vector<long> target;

    return pathSum(root, targetSum, target);
}

int pathSum(TreeNode* root, int targetSum, vector<long> &target) {
    if (!root) {
        return 0;
    }

    target.push_back(targetSum);

    int path = 0;

    for (size_t i = 0; i < target.size(); i++) {
        target[i] -= root->val;

        if (target[i] == 0) {
            path++;
        }
    }

    cout << target;

    path += pathSum(root->left, targetSum, target);
    path += pathSum(root->right, targetSum, target);

    target.pop_back();

    for (size_t i = 0; i < target.size(); i++) {
        target[i] += root->val;
    }

    return path;
}
