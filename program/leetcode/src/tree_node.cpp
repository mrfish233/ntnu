#include "tree_node.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

std::vector<std::string> stringToVector(std::string str) {
    std::vector<std::string> nodes;

    for (size_t i = 1; i < str.length()-1; i++) {
        std::string temp;

        while (isalnum(str[i]) || str[i] == '-') {
            temp += str[i++];
        }

        nodes.push_back(temp);
    }

    // cout << "[ ";
    // for (auto node : nodes) {
    //     cout << node << " ";
    // }
    // cout << "]\n";

    return nodes;
}

TreeNode *initNodes(std::vector<std::string> nodes) {
    return initNodes(nodes, 0);
}

TreeNode *initNodes(std::vector<std::string> nodes, size_t i) {
    if (i >= nodes.size() || nodes[i] == "null") {
        return nullptr;
    }

    TreeNode *head = new TreeNode(std::stoi(nodes[i]));
    head->left  = initNodes(nodes, 2*i + 1);
    head->right = initNodes(nodes, 2*i + 2);

    return head;
}

void printTree(TreeNode *root) {
    std::cout << "[ ";

    printNode(root);

    std::cout << "]\n";
}

void printNode(TreeNode *node) {
    if (node == nullptr) {
        std::cout << "NULL ";
        return;
    }

    std::cout << node->val << " ";

    printNode(node->left);
    printNode(node->right);
}
