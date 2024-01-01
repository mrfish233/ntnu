#include <stdio.h>
#include <stdint.h>

void dayOfWeek(int32_t month, int32_t day) {
    int32_t days = day;

    switch (month) {
        case 2:  days +=  31; break;
        case 3:  days +=  59; break;
        case 4:  days +=  90; break;
        case 5:  days += 120; break;
        case 6:  days += 151; break;
        case 7:  days += 181; break;
        case 8:  days += 212; break;
        case 9:  days += 243; break;
        case 10: days += 273; break;
        case 11: days += 304; break;
        case 12: days += 334; break;
        default: break;
    }

    switch (days % 7) {
        case 0: printf("Friday\n"); break;
        case 1: printf("Saturday\n"); break;
        case 2: printf("Sunday\n"); break;
        case 3: printf("Monday\n"); break;
        case 4: printf("Tuesday\n"); break;
        case 5: printf("Wednesday\n"); break;
        case 6: printf("Thursday\n"); break;
        default: break;
    }

    return;
}

int main() {
    int32_t cases = 0;

    scanf("%d", &cases);

    while(cases--) {
        int32_t month = 0, day = 0;

        scanf("%d%d", &month, &day);
        dayOfWeek(month, day);
    }

    return 0;
}
