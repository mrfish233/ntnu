#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

std::vector<std::string> stringToVector(std::string str);

TreeNode *initNodes(std::string str);

void printTree(TreeNode *root);
void printNode(TreeNode *node);
