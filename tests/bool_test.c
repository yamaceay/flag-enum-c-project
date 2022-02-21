#include "bool.h"

int main() {
    int len = 10;
    int num = 13;
    bool* bits = new_b(len);

    to_b(bits, num, len);

    for (int i = 0; i < len; i++) {
        printf("%2d: %d\n", i, bits[i]);
    }

    printf("Actual: %d, Expected: %d\n", from_b(bits, len), num);
}