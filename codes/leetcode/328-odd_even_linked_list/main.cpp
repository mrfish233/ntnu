#include <iostream>
#include "list_node.h"

using namespace std;

ListNode* oddEvenList(ListNode* head);

int main() {
    int n;
    while (cin >> n) {
        ListNode *head = initNodes(n);
        printNode(head);

        head = oddEvenList(head);
        printNode(head);
    }

    return 0;
}

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *oddHead = head, *evenHead = head->next, *oddNext, *evenNext = head->next;
    while (evenNext != nullptr && evenNext->next != nullptr) {
        oddNext = evenNext->next;       // [ 1(oH)->2(eH,eN)->3(oN)->4->5 ]

        evenNext->next = oddNext->next; // [ 1(oH)->2(eH,eN)->4->5 ] [ 3(oN)->4 ]
        oddNext->next  = evenHead;      // [ 1(oH)->2(eH,eN)->4->5 ] [ 3(oN)->2(eH,eN)->4->5 ]
        oddHead->next  = oddNext;       // [ 1(oH)->3(oN)->2(eH,eN)->4->5 ]

        oddHead  = oddHead->next;       // [ 1->3(oH,oN)->2(eH,eN)->4->5 ]
        evenNext = evenNext->next;      // [ 1->3(oH,oN)->2(eH)->4(eN)->5 ]
    }

    return head;
}
