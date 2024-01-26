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

    return nodes;
}

TreeNode *initNodes(std::string str) {
    std::vector<std::string> nodes = stringToVector(str);

    if (nodes.size() <= 0 || nodes[0] == "null") {
        return nullptr;
    }

    TreeNode *head = new TreeNode(std::stoi(nodes[0]));

    std::queue<TreeNode *> nodesQueue;
    nodesQueue.push(head);

    for (size_t i = 1; i < nodes.size(); i++) {
        TreeNode *temp = nodesQueue.front();

        if (nodes[i] == "null") {
            temp->left = nullptr;
        } else {
            temp->left = new TreeNode(std::stoi(nodes[i]));
            nodesQueue.push(temp->left);
        }

        i++;

        if (i >= nodes.size()) {
            break;
        } else if (nodes[i] == "null") {
            temp->right = nullptr;
        } else {
            temp->right = new TreeNode(std::stoi(nodes[i]));
            nodesQueue.push(temp->right);
        }

        nodesQueue.pop();
    }

    // return initNodes(nodes, 0);
    return head;
}

// TreeNode *initNodes(std::vector<std::string> nodes, size_t i) {
//     if (i >= nodes.size() || nodes[i] == "null") {
//         return nullptr;
//     }

//     TreeNode *head = new TreeNode(std::stoi(nodes[i]));
//     head->left  = initNodes(nodes, 2*i + 1);
//     head->right = initNodes(nodes, 2*i + 2);

//     return head;
// }

void printTree(TreeNode *root) {
    std::cout << "[ ";

    printNode(root);

    std::cout << "]\n";
}

void printNode(TreeNode *node) {
    if (node == nullptr) {
        std::cout << "n ";
        return;
    }

    std::cout << node->val << " ";

    printNode(node->left);
    printNode(node->right);
}
