#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <assert.h>
#include "linked_list.h"

typedef struct ListStack {
	ListNode *top;
	int32_t size;
} ListStack;

/*
 * Create new stack
 */
ListStack *newListStack();

/*
 * Free stack
 */
void freeListStack(ListStack *stack);

/*
 * Size of stack
 */
int32_t sizeOfListStack(ListStack *stack);

/*
 * Is empty stack
 */
int32_t isEmptyListStack(ListStack *stack);

/*
 * Peek stack
 */
int32_t peekListStack(ListStack *stack);

/*
 * Push stack
 */
void pushListStack(ListStack *stack, int32_t value);

/*
 * Pop stack
 */
int32_t popListStack(ListStack *stack);

#endif
