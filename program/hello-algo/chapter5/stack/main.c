#include "stack.h"

int main() {
	ListStack *stack = newListStack();
	int32_t result = 0, size = 0;

	size   = sizeOfListStack(stack);
	printf("[1] size=%d\n\n", size);

	// Push nodes
	pushListStack(stack, 1);
	pushListStack(stack, 7);
	pushListStack(stack, 3);
	pushListStack(stack, 8);

	// Print stack
	printf("[2] ");
	printListNode(stack->top);

	result = peekListStack(stack);
	size   = sizeOfListStack(stack);
	printf("[2] top=%d, size=%d\n\n", result, size);

	// Pop and push nodes
	popListStack(stack);
	popListStack(stack);

	pushListStack(stack, 30);

	// Print stack
	printf("[3] ");
	printListNode(stack->top);

	result = peekListStack(stack);
	size   = sizeOfListStack(stack);
	printf("[3] top=%d, size=%d\n", result, size);

	// Free stack
	freeListStack(stack);

	return 0;
}