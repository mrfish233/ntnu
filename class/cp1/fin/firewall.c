#include "firewall.h"

#define MAX_RULES 100

static int32_t (*rules[100])(const uint8_t *, const int32_t, uint8_t **, int32_t *) = {NULL};

int32_t set_rule(int32_t idx, int32_t (*rule)(const uint8_t *p_input_packet, const int32_t input_size, uint8_t **pp_output_packet, int32_t *p_output_size)) {
    if (rules[idx] != NULL) {
        return -1;
    }

    rules[idx] = rule;

    return 0;
}

int32_t unset_rule(int32_t idx) {
    if (rules[idx] == NULL) {
        return -1;
    }

    rules[idx] = NULL;

    return 0;
}

int32_t filter(const uint8_t *p_input_packets, const int32_t input_size, uint8_t **pp_output_packets, int32_t *p_output_size) {
    if (p_input_packets == NULL || input_size < 0 || p_output_size == NULL) {
        return -1;
    }

    for (size_t i = 0; i < MAX_RULES; i++) {
        if (rules[i] == NULL) {
            continue;
        }

        (*rules[i])(p_input_packets, input_size, pp_output_packets, p_output_size);
    }

    return 0;
}
