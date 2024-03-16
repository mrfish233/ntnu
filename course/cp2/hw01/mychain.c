#include "mychain.h"

int32_t chain_rule(sPoly *pResult, const sPoly *pFy, const sPoly *pFx) {
    if (pResult == NULL || !isValid(pFy) || !isValid(pFx)) {
        return -1;
    }

    sPoly fyPrime = {0, NULL, NULL};
    sPoly fxPrime = {0, NULL, NULL};

    if (derivative(&fyPrime, pFy) == -1 || derivative(&fxPrime, pFx) == -1) {
        return -1;
    }

    // printf("fyPrime:\n");
    // for (uint32_t i = 0; i < fyPrime.size; i++) {
    //     printf("%3d %3d\n", fyPrime.pCoefficients[i], fyPrime.pPowers[i]);
    // }

    // printf("fxPrime:\n");
    // for (uint32_t i = 0; i < fxPrime.size; i++) {
    //     printf("%3d %3d\n", fxPrime.pCoefficients[i], fxPrime.pPowers[i]);
    // }

    // Reset pResult

    clear(pResult);

    // Substitute fx into fyPrime

    if (substitute(pResult, &fyPrime, pFx) == -1) {
        return -1;
    }

    // Multiply the result with fxPrime

    if (multiply(pResult, &fxPrime) == -1) {
        return -1;
    }

    clear(&fyPrime);
    clear(&fxPrime);

    return 0;
}

bool isValid(const sPoly *pF) {
    if (pF == NULL || pF->size == 0) {
        return false;
    }

    return true;
}

int32_t derivative(sPoly *pResult, const sPoly *pF) {
    if (pResult == NULL || !isValid(pF)) {
        return -1;
    }

    uint32_t size = pF->size;

    if (pF->pPowers[size - 1] == 0) {
        size--;
    }

    for (uint32_t i = 0; i < size; i++) {
        uint32_t power = pF->pPowers[i];
        int32_t coefficient = pF->pCoefficients[i];

        if (addTerm(pResult, power - 1, coefficient * power) == -1) {
            return -1;
        }
    }

    return 0;
}

int32_t substitute(sPoly *pResult, const sPoly *pG, const sPoly *pF) {
    if (pResult == NULL || !isValid(pG) || !isValid(pF)) {
        return -1;
    }

    sPoly temp = {1, NULL, NULL};
    addTerm(&temp, 0, 1);

    uint32_t currentPower = 0;

    for (uint32_t i = pG->size; i > 0; i--) {
        while (currentPower < pG->pPowers[i - 1]) {
            if (multiply(&temp, pF) == -1) {
                return -1;
            }

            currentPower++;
        }

        sPoly curr = {0, NULL, NULL};

        if (addTerm(&curr, 0, pG->pCoefficients[i - 1]) == -1) {
            return -1;
        }

        if (multiply(&curr, &temp) == -1) {
            return -1;
        }

        if (add(pResult, &curr) == -1) {
            return -1;
        }
    }

    return 0;
}

int32_t add(sPoly *pResult, const sPoly *pF) {
    if (pResult == NULL || !isValid(pF)) {
        return -1;
    }

    for (uint32_t i = 0; i < pF->size; i++) {
        if (addTerm(pResult, pF->pPowers[i], pF->pCoefficients[i]) == -1) {
            return -1;
        }
    }

    return 0;
}

int32_t multiply(sPoly *pResult, const sPoly *pF) {
    if (pResult == NULL || !isValid(pF)) {
        return -1;
    }

    sPoly temp = {0, NULL, NULL};

    // Multiply pF with pResult

    for (uint32_t i = 0; i < pF->size; i++) {
        for (uint32_t j = 0; j < pResult->size; j++) {
            uint32_t power = pF->pPowers[i] + pResult->pPowers[j];
            int32_t coefficient = pF->pCoefficients[i] * pResult->pCoefficients[j];

            if (addTerm(&temp, power, coefficient) == -1) {
                return -1;
            }
        }
    }

    // Copy temp to pResult

    clear(pResult);

    if (add(pResult, &temp) == -1) {
        return -1;
    }

    clear(&temp);

    return 0;
}

int32_t addTerm(sPoly *pF, uint32_t power, int32_t coefficient) {
    if (pF == NULL) {
        return -1;
    } else if (coefficient == 0) {
        return 0;
    }

    // Check if the polynomial is empty

    if (pF->size == 0 || pF->pPowers == NULL || pF->pCoefficients == NULL) {
        pF->size = 1;
        pF->pPowers = (uint32_t *) calloc(1, sizeof(uint32_t));
        pF->pCoefficients = (int32_t *) calloc(1, sizeof(int32_t));

        pF->pPowers[0] = power;
        pF->pCoefficients[0] = coefficient;

        return 0;
    }

    // Check if the power already exists in the polynomial

    uint32_t size = pF->size;

    for (uint32_t i = 0; i < size; i++) {
        if (pF->pPowers[i] == power) {
            pF->pCoefficients[i] += coefficient;
            return 0;
        }
    }

    // Add the new term to the polynomial, and sort the polynomial

    pF->size++;
    pF->pPowers = (uint32_t *) reallocarray(pF->pPowers, pF->size, sizeof(uint32_t));
    pF->pCoefficients = (int32_t *) reallocarray(pF->pCoefficients, pF->size, sizeof(int32_t));

    for (uint32_t i = 0; i < pF->size; i++) {
        if (i == pF->size - 1 || pF->pPowers[i] < power) {
            for (uint32_t j = pF->size - 1; j > i; j--) {
                pF->pPowers[j] = pF->pPowers[j - 1];
                pF->pCoefficients[j] = pF->pCoefficients[j - 1];
            }

            pF->pPowers[i] = power;
            pF->pCoefficients[i] = coefficient;

            break;
        }
    }

    return 0;
}

void clear(sPoly *pF) {
    if (pF == NULL) {
        return;
    }

    pF->size = 0;

    if (pF->pPowers != NULL) {
        free(pF->pPowers);
        pF->pPowers = NULL;
    }

    if (pF->pCoefficients != NULL) {
        free(pF->pCoefficients);
        pF->pCoefficients = NULL;
    }
}
