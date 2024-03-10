#pragma once

struct ListNode {
    int val;
    ListNode *next;

    ListNode();
    ListNode(int x);
};

/**
 * Insert a new node.
 * @param curr The node before the new node after inserted.
 * @param node The node to be inserted.
 */
void insert(ListNode *curr, ListNode *node);

/**
 * Remove a node.
 * @param curr The node before the node to be removed.
 */
void remove(ListNode *curr);

/**
 * Find a node.
 * @param head The head of the linked list.
 * @param target The target value of the node.
 * @return The index of the node, -1 if not found.
 */
int find(ListNode *head, int target);
