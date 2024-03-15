#include "mycal.h"

int32_t calculate(char *pExpr, int32_t base, char **ppResult) {
    if (pExpr == NULL || ppResult == NULL) {
        return -1;
    }

    int64_t flag = 1, operandSize = 0, operatorSize = 0;
    int64_t *operands = NULL, check = 0;
    char *operators = NULL;

    char *token = strtok(pExpr, " ");

    while (token != NULL) {
        if (flag) {
            check = addNewOperand(&operands, operandSize, token);
            operandSize++;
        } else {
            check = addNewOperator(&operators, operatorSize, token);
            operatorSize++;
        }

        if (check == -1) {
            freeMemory(operands, operators);
            return -1;
        }

        flag  = !flag;
        token = strtok(NULL, " ");
    }

    int64_t sum = 0;

    check = calculateResult(operands, operators, operandSize, operatorSize, &sum);

    if (check == -1) {
        freeMemory(operands, operators);
        return -1;
    }

    // printf("=%ld\n", sum);

    check = convertToBaseStr(sum, base, ppResult);

    freeMemory(operands, operators);
    return check;
}

int64_t convertToBase10Int(char *operand) {
    // Check if the base is valid

    char *pBase = strchr(operand, '_');

    if (pBase == NULL) {
        return -1;
    }

    pBase++;

    char *check = NULL;
    int64_t base = strtol(pBase, &check, 10);

    if (*check != '\0' || base < 2 || base > 16) {
        return -1;
    }

    // Check if the number is valid

    int64_t number = strtol(operand, &check, base);

    if (*check != '_' || *operand == '_') {
        return -1;
    }

    return number;
}

int32_t convertToBaseStr(int64_t number, int32_t base, char **ppResult) {
    if (ppResult == NULL) {
        return -1;
    }

    if (base < 2 || base > 16) {
        return -1;
    }

    // Calculate the size of the result

    int64_t temp, size = 0, flag = 0, baseSize = 0;

    if (number < 0) {
        flag = 1;
        number = -number;
    }

    temp = number;

    while (temp > 0) {
        temp /= base;
        size++;
    }

    if (size == 0) { // number is 0
        size = 1;
    }

    if (base >= 10) {
        baseSize = 3;
    } else {
        baseSize = 2;
    }

    int64_t totalSize = size + flag + baseSize + 1;

    // Set the result

    *ppResult = (char *) calloc(totalSize, sizeof(char));

    temp = number;

    for (int64_t i = size - 1; i >= 0; i--) {
        int64_t digit = temp % base;

        // printf("%ld\n", temp);

        if (digit < 10) {
            (*ppResult)[i + flag] = digit + '0';
        } else {
            (*ppResult)[i + flag] = digit - 10 + 'A';
        }

        temp /= base;
    }

    if (flag) {
        (*ppResult)[0] = '-';
    }

    // Set the base to the result

    if (base >= 10) {
        (*ppResult)[size + flag] = '_';
        (*ppResult)[size + flag + 1] = '1';
        (*ppResult)[size + flag + 2] = base - 10 + '0';
    } else {
        (*ppResult)[size + flag] = '_';
        (*ppResult)[size + flag + 1] = base + '0';
    }

    return 0;
}

int32_t addNewOperand(int64_t **operands, int64_t size, char *operand) {
    int64_t num = convertToBase10Int(operand);

    // printf("%ld", num);

    if (num == -1) {
        return -1;
    }

    if (*operands == NULL) {
        *operands = (int64_t *) calloc(1, sizeof(int64_t));
    } else {
        *operands = (int64_t *) reallocarray(*operands, size + 1, sizeof(int64_t));
    }

    (*operands)[size] = num;

    return 0;
}

int32_t addNewOperator(char **operators, int64_t size, char *operator) {
    if (strlen(operator) != 1) {
        return -1;
    }

    char op = operator[0];

    if (op != '+' && op != '-' && op != '*') {
        return -1;
    }

    // printf("%c", op);

    if (*operators == NULL) {
        *operators = (char *) calloc(1, sizeof(char));
    } else {
        *operators = (char *) reallocarray(*operators, size + 1, sizeof(char));
    }

    (*operators)[size] = op;

    return 0;
}

int32_t calculateResult(int64_t *operands, char *operators, int64_t operandSize, int64_t operatorSize, int64_t *pResult) {
    if (operands == NULL || pResult == NULL) {
        return -1;
    }

    if (operandSize - operatorSize != 1) {
        return -1;
    }

    // Calculate the multiplication

    for (int64_t i = 0; i < operatorSize; i++) {
        if (operators[i] == '*') {
            operands[i] *= operands[i + 1];

            for (int64_t j = i + 1; j < operandSize - 1; j++) {
                operands[j] = operands[j + 1];
            }

            for (int64_t j = i; j < operatorSize - 1; j++) {
                operators[j] = operators[j + 1];
            }

            operandSize--;
            operatorSize--;
            i--;
        }
    }

    // Calculate the addition and subtraction

    int64_t result = operands[0];

    for (int64_t i = 0; i < operatorSize; i++) {
        if (operators[i] == '+') {
            result += operands[i + 1];
        } else if (operators[i] == '-') {
            result -= operands[i + 1];
        }
    }

    // printf("%ld\n", result);

    *pResult = result;

    return 0;
}

void freeMemory(int64_t *operands, char *operators) {
    if (operands != NULL) {
        free(operands);
    }

    if (operators != NULL) {
        free(operators);
    }
}
