#include "linked_list.h"

ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}

void insert(ListNode *curr, ListNode *node) {
    ListNode *temp = curr->next;

    curr->next = node;
    node->next = temp;
}

void remove(ListNode *curr) {
    if (curr->next == nullptr) {
        return;
    }

    ListNode *temp = curr->next;

    curr->next = temp->next;

    delete temp;
}

int find(ListNode *head, int target) {
    int index = 0;

    while (head != nullptr) {
        if (head->val == target) {
            return index;
        }

        head = head->next;
        index++;
    }

    return -1;
}
