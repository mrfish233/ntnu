#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ListNode {
	int32_t value;
	struct ListNode *next;
} ListNode;

/*
 * Create new list node with a value
 */
ListNode *newListNode(int value);

/*
 * Access list node
 */
ListNode *accessListNode(ListNode *headNode, int32_t index);

/*
 * Find value in list node
 */
int32_t findListNode(ListNode *headNode, int32_t target);

/*
 * Insert list node
 */
void insertListNode(ListNode *prevNode, ListNode *insertNode);

/*
 * Delete list node
 */
void removeListNode(ListNode *prevNode);

/*
 * Print list nodes
 */
void printListNode(ListNode *headNode);

/*
 * Free nodes
 */
void freeListNode(ListNode *headNode);

#endif // LINKED_LIST_H_INCLUDED
