#include "tas.h"

void button_set_frame(uint8_t **src, size_t *size, const uint8_t button, const uint64_t start_frame, const uint64_t end_frame) {
    if (size == NULL || start_frame > end_frame) {
        return;
    }

    if (end_frame > *size) {
        if (*src == NULL) {
            *src = calloc(end_frame + 1, sizeof(uint8_t));
        } else {
            *src = realloc(*src, (end_frame + 1) * sizeof(uint8_t));
        }
    }

    for (size_t i = start_frame; i <= end_frame; i++) {
        (*src)[i] = (*src)[i] | button;
    }

    *size = end_frame + 1;
}

void button_unset_frame(uint8_t *src, const size_t size, const uint8_t button, const uint64_t start_frame, const uint64_t end_frame) {
    if (src == NULL || start_frame > end_frame) {
        return;
    }

    for (size_t i = start_frame; i <= end_frame; i++) {
        if (i >= size) {
            break;
        }

        uint8_t temp = 0;
        for (size_t j = 8; j > 0; j--) {
            uint8_t sourceBit = (src[i] >> (j-1)) & 1;
            uint8_t buttonBit = (button >> (j-1)) & 1;

            temp += sourceBit & !buttonBit;

            if (j != 1) {
                temp = temp << 1;
            }
        }
        src[i] = temp;
    }
}
