#include <iostream>
#include "../src/list_node.h"

using namespace std;

ListNode* deleteMiddle(ListNode* head);

int main() {
    int n;
    cin >> n;

    ListNode *head = initNodes(n);
    printNode(head);

    head = deleteMiddle(head);
    printNode(head);

    return 0;
}

ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode *slow = head, *fast = head, *node;
    while (fast != nullptr && fast->next != nullptr) {
        node = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    node->next = slow->next;
    delete slow;

    return head;
}
