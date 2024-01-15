#include <iostream>
#include "../src/list_node.h"

using namespace std;

ListNode* reverseList(ListNode* head);

int main() {
    int n;
    while (cin >> n) {
        ListNode *head = initNodes(n);
        printNode(head);

        head = reverseList(head);
        printNode(head);
    }

    return 0;
}

ListNode* reverseList(ListNode* head) {
    // Solution 1 (iterative)

    // if (head == nullptr) {
    //     return head;
    // }

    // ListNode *prev = head;
    // ListNode *temp = head;
    // ListNode *curr = head->next;

    // // temp: the head of lists
    // // prev: first node of initial lists (constant)
    // // curr: the node to be moved to front

    // // Initial: [ 1(t,p)->2(c)->3->4->5 ]
    // // First loop:
    // // [ 1(t,p)->3->4->5 ] [ 2(c)->3->4->5 ]
    // // [ 2(c)->1(t,p)->3->4->5 ]
    // // [ 2(t,c)->1(p)->3->4->5 ]
    // // [ 2(t)->1(p)->3(c)->4->5 ]
    // // Second loop:
    // // [ 2(t)->1(p)->4->5 ] [ 3(c)->4->5 ]
    // // [ 3(c)->2(t)->1(p)->4->5 ]
    // // [ 3(t,c)->2->1(p)->4->5 ]
    // // [ 3(t)->2->1(p)->4(c)->5 ]

    // while (curr != nullptr) {
    //     prev->next = curr->next;
    //     curr->next = temp;

    //     temp = curr;
    //     curr = prev->next;
    // }

    // return temp;

    // ========================

    // Solution 2 (iterative, more simple)

    // ListNode *prev = nullptr, *temp;

    // while (head != nullptr) {
    //     temp = head;
    //     head = head->next;

    //     temp->next = prev;

    //     prev = temp;
    // }

    // return prev;

    // ========================

    // Solution 3 (recursive)

    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *last = nullptr, *temp = head->next;
    ListNode *curr = reverseList(temp);

    temp->next = head;
    head->next = last;

    return curr;
}
