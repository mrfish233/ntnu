#include <stdio.h>
#include <stdint.h>
#include <math.h>

/**
 * TLV implementation.
 * @param pByteArray The array of tlv-encoded data.
 * @param size The size of array.
 * @return 0 if success, -1 if invalid array.
 */
int32_t run(uint8_t *pByteArray, int32_t size);
