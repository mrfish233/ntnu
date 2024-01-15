#include "linked_list.h"

int main() {
	ListNode *node0, *node1, *node2, *node3;
	ListNode *access;
	int32_t find1 = 0, find2 = 0;
	int32_t result1 = 0, result2 = 0;

	node0 = newListNode(3);
	node1 = newListNode(7);
	node2 = newListNode(9);
	node3 = newListNode(6);

	// Insert nodes
	insertListNode(node0, node1);
	insertListNode(node1, node2);
	insertListNode(node2, node3);

	// Print the nodes from node0
	printListNode(node0);

	access = accessListNode(node0, 2);
	printf("node2 = %d\n", access->value);

	// Remove the node next to node1
	removeListNode(node1);
	printf("node2 removed\n");

	// Print the nodes from node0
	printListNode(node0);

	access = accessListNode(node0, 2);
	printf("node2 = %d\n", access->value);

	// Find node
	find1 = 6;
	find2 = 7;
	result1 = findListNode(node0, find1);
	result2 = findListNode(node0, find2);

	printf("[%d]: %d; [%d]: %d\n", find1, result1, find2, result2);

	// Free nodes
	freeListNode(node0);

	return 0;
}
