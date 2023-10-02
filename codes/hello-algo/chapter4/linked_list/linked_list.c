#include "linked_list.h"

ListNode *newListNode(int value) {
	ListNode *newNode;

	// Create new node
	newNode = (ListNode *) malloc(sizeof(ListNode));

	// Set new node
	newNode->value = value;
	newNode->next  = NULL;

	return newNode;
}

ListNode *accessListNode(ListNode *headNode, int32_t index) {
	ListNode *currNode = headNode;

	// Return null if index < 0
	if (index < 0) return NULL;

	// Find the node by index
	while (currNode != NULL && index) {
		currNode = currNode->next;
		index--;
	}

	return currNode;
}

int32_t findListNode(ListNode *headNode, int32_t target) {
	ListNode *currNode = headNode;
	int32_t index = 0;

	while (currNode != NULL) {
		// Return index if found
		if (currNode->value == target) return index;

		// Go to next node
		currNode = currNode->next;
		index++;
	}

	return -1;
}

void insertListNode(ListNode *prevNode, ListNode *insertNode) {
	ListNode *nextNode = prevNode->next;

	// insertNode -> nextNode
	insertNode->next = nextNode;

	// prevNode -> insertNode
	prevNode->next   = insertNode;
}

void removeListNode(ListNode *prevNode) {
	ListNode *tempNode = prevNode->next;

	// Return if null node
	if (tempNode == NULL) return;

	// Next node is now the node after temp node
	prevNode->next = tempNode->next;

	// Free temp node
	free(tempNode);
}

void printListNode(ListNode *headNode) {
	ListNode *nextNode = headNode;

	// node1 -> node2 -> ... -> nodeN -> NULL
	while (nextNode != NULL) {
		printf("%d -> ", nextNode->value);
		nextNode = nextNode->next;
	}
	printf("NULL\n");
	
}

void freeListNode(ListNode *headNode) {
	ListNode *currNode, *nextNode, *tempNode;

	currNode = headNode;
	nextNode = headNode->next;

	// Free the nodes until next node is null
	while (nextNode != NULL) {
		// Temp node to be freed
		tempNode = currNode;

		// Move curr node to next node
		currNode = nextNode;

		// Move next node to next next node
		nextNode = nextNode->next;

		// Free temp node
		free(tempNode);
	}

	// Free the last node
	free(currNode);
}
