#include <iostream>
#include "list_node.h"

using namespace std;

int pairSum(ListNode* head);
ListNode* reverseList(ListNode* head);

int main() {
    int n;
    while (cin >> n) {
        ListNode *head = initNodes(n);
        printNode(head);

        cout << "max: " << pairSum(head) << endl;
    }

    return 0;
}

int pairSum(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *tail = reverseList(slow);

    int maxSum = 0;

    while (tail != nullptr) {
        int tmpSum = head->val + tail->val;

        if (maxSum < tmpSum) {
            maxSum = tmpSum;
        }

        head = head->next;
        tail = tail->next;
    }

    return maxSum;
}

ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *temp;

    while (head != nullptr) {
        temp = head;
        head = head->next;

        temp->next = prev;

        prev = temp;
    }

    return prev;
}
