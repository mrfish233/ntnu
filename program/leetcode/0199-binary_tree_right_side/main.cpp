#include <iostream>
#include <vector>
#include <string>
#include "../src/tree_node.h"

using namespace std;

vector<int> rightSideView(TreeNode* root);

int main() {
    string str;

    while (cin >> str) {
        TreeNode *root = initNodes(str);
        vector<int> view = rightSideView(root);

        cout << "[ ";
        for (int val : view) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}

vector<int> rightSideView(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<int> view;
    view.push_back(root->val);

    vector<int> right = rightSideView(root->right);
    vector<int> left  = rightSideView(root->left);

    view.insert(end(view), begin(right), end(right));

    if (size(left) > size(right)) {
        view.insert(end(view), begin(left) + size(right), end(left));
    }

    return view;
}
