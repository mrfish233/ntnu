#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Calculate the arithmetic expression.
 * @param pEpr the arithmetic expression with the following format:
 * <operand 1> (operator 1) <operand 2> (operator 2) ... (operator n-1) <operand n>;
 * operand: a number in base between 2 and 16, format with <digits_base>, example: 123_10, 1A_16, ...;
 * operator: +, -, *
 * @param base the base that is used to show the arithmetic result. (2-16)
 * @param ppResult the arithmetic result string.
 * @return 0: Success; -1: error input
 */
int32_t calculate(char *pExpr, int32_t base, char **ppResult);

/**
 * Convert the operand to base 10.
 * @param operand the operand string.
 * @return the base 10 number; -1: error input
 */
int64_t convertToBase10Int(char *operand);

/**
 * Convert the number to the base.
 * @param num the number.
 * @param base the base.
 * @param ppResult the result string.
 * @return 0: Success; -1: error input
 */
int32_t convertToBaseStr(int64_t number, int32_t base, char **ppResult);

/**
 * Add a new operand to the operand array.
 * @param operands the operand array.
 * @param size the size of the operand array.
 * @param operand the new operand.
 * @return 0: Success; -1: error input
 */
int32_t addNewOperand(int64_t **operands, int64_t size, char *operand);

/**
 * Add a new operator to the operator array.
 * @param operators the operator array.
 * @param size the size of the operator array.
 * @param operator the new operator.
 */
int32_t addNewOperator(char **operators, int64_t size, char *operator);

/**
 * Calculate the result of the arithmetic expression.
 * @param operand the operand array.
 * @param operator the operator array.
 * @param operandSize the size of the operand array.
 * @param operatorSize the size of the operator array.
 * @param pResult the result of the arithmetic expression.
 * @return 0: Success; -1: error input
 */
int32_t calculateResult(int64_t *operands, char *operators, int64_t operandSize, int64_t operatorSize, int64_t *pResult);

/**
 * Free the memory of the operand and operator array.
 * @param operands the operand array.
 * @param operators the operator array.
 * @return 0: Success; -1: error input
 */
void freeMemory(int64_t *operands, char *operators);
