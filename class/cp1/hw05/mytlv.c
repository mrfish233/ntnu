#include "mytlv.h"

/**
 * Convert data array to number.
 * @param array The tlv array.
 * @param head The index of current data.
 * @param len The length of data.
 * @return The number.
 */
static uint64_t dataToNum(uint8_t *array, int32_t head, uint16_t len);

/**
 * Count the digit of number.
 * @param num The number.
 * @return The digit of number.
 */
static uint64_t digitCount(uint64_t num);

/**
 * Check if current TLV is cancelled.
 * @param array The tlv array.
 * @param size The size of tlv array.
 * @param head The index of current data.
 * @return Total length to be skipped. -1 if invalid input.
 */
static int32_t cancelTLV(uint8_t *array, int32_t size, int32_t head);

int32_t run(uint8_t *pByteArray, int32_t size) {
    if (pByteArray == NULL || size < 0) {
        return -1;
    }

    uint8_t  type   = 0;
    uint16_t length = 0;
    uint64_t result = 0;

    int32_t i = 0;
    while (i < size) {
        // Type of TLV

        type = pByteArray[i];
        i += 1;

        if (type == 0 || type > 10) {
            continue;
        } else if (i + 1 == size) {
            return -1;
        }

        // Length of value

        length = (pByteArray[i + 1] << 8) + pByteArray[i];
        i += 2;

        if (i + length > size) {
            return -1;
        }

        if (length != 0 && (type == 4 || type == 5 || type == 8 || type == 9 || type == 10)) {
            return -1;
        }

        // Check if cancelled

        int32_t cancel = cancelTLV(pByteArray, size, i + length);
        if (cancel == -1) {
            return -1;
        } else if (cancel % 2 == 1) {
            i += (length + cancel * 3);
            continue;
        }

        // TLV process

        if (type == 1) {
            result = dataToNum(pByteArray, i, length);
        } else if (type == 2) {
            result += dataToNum(pByteArray, i, length);
        } else if (type == 3) {
            result *= dataToNum(pByteArray, i, length);
        } else if (type == 4) {
            result /= 2;
        } else if (type == 5) {
            result /= 10;
        } else if (type == 6) {
            // Append result to value
            result = dataToNum(pByteArray, i, length) * (uint64_t) pow(10, digitCount(result)) + result;
        } else if (type == 7) {
            // Append value to result
            result = dataToNum(pByteArray, i, length) + (uint64_t) pow(10, length) * result;
        } else if (type == 8) {
            result = 0;
        } else if (type == 9) {
            printf("%lu\n", result);
        } else if (type == 10) {
            return -1;
        }

        i += (length + cancel * 3);
    }

    return 0;
}

static uint64_t dataToNum(uint8_t *array, int32_t head, uint16_t len) {
    uint64_t num = 0;
    for (int32_t i = head; i < head + len; i++) {
        num = num * 10 + array[i];
    }

    return num;
}

static uint64_t digitCount(uint64_t num) {
    return (num == 0) ? 1 : (uint64_t) log10(num) + 1;
}

static int32_t cancelTLV(uint8_t *array, int32_t size, int32_t head) {
    int32_t total = 0;

    int32_t i = head;
    while (i < size) {
        if (array[i] != 0x0A) {
            break;
        }

        if (i + 1 == size || i + 2 == size) {
            return -1;
        }

        if (array[i + 1] != 0 || array[i + 2] != 0) {
            return -1;
        }

        i += 3;
        total++;
    }

    return total;
}
