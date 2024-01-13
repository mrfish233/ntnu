#include "list_node.h"

ListNode *initNodes(int n) {
    ListNode *curr = nullptr, *head = nullptr;

    while (n--) {
        int val;
        std::cin >> val;

        if (curr == nullptr) {
            curr = new ListNode(val);
            head = curr;
        } else {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
    }

    return head;
}

void printNode(ListNode *head) {
    std::cout << "[ ";

    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }

    std::cout << "]\n";
}
