#include "stack.h"

ListStack *newListStack() {
	ListStack *stack = malloc(sizeof(ListStack));
	stack->top  = NULL;
	stack->size = 0;

	return stack;
}

void freeListStack(ListStack *stack) {
	freeListNode(stack->top);
	free(stack);
}

int32_t sizeOfListStack(ListStack *stack) {
	assert(stack);

	return stack->size;
}

int32_t isEmptyListStack(ListStack *stack) {
	assert(stack);

	return (stack->size == 0);
}

int32_t peekListStack(ListStack *stack) {
	assert(stack);
	assert(stack->size != 0);

	return stack->top->value;
}

void pushListStack(ListStack *stack, int32_t value) {
	assert(stack);

	ListNode *newNode = newListNode(value);

	// Add new node
	newNode->next = stack->top;

	// Update stack
	stack->top = newNode;
	stack->size++;
}

int32_t popListStack(ListStack *stack) {
	if (stack->size == 0) {
		printf("Stack is empty.\n");
		return INT32_MAX;
	}
	assert(stack);

	ListNode *tempNode = stack->top;
	int32_t value = peekListStack(stack);

	// Update stack
	stack->top = tempNode->next;
	stack->size--;

	// Free top node
	free(tempNode);

	// Return pop node value
	return value;
}
