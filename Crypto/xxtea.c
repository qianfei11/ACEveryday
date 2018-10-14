#include <stdio.h>
#include <stdint.h>
#define DELTA 0x9e3779b9
#define MX (((z >> 5 ^ y << 2) + (y >> 3 ^ z << 4)) ^ ((sum ^ y) + (key[(p & 3) ^ e] ^ e)))

void btea(uint32_t *v, int n, uint32_t const key[4]) {
    uint32_t y, z, sum;
    unsigned p, rounds, e;
    if(n > 1) {
        rounds = 6 + 52 / n;
        sum = 0;
        z = v[n - 1];
        do {
            sum += DELTA;
            e = (sum >> 2) & 3;
            for(p = 0; p < n - 1; p++) {
                y = v[p + 1];
                z = v[p] += MX;
            }
            y = v[0];
            z = v[n - 1] += MX;
        } while(--rounds);
    }
}

int main() {
    uint32_t v[2] = {1, 2};
    uint32_t const k[4] = {2, 2, 3, 4};
    int n = 2;
    printf("origin: %u %u\n", v[0], v[1]);
    btea(v, n, k);
    printf("encrypt: %u %u\n", v[0], v[1]);
    btea(v, -n, k);
    printf("decrypt: %u %u\n", v[0], v[1]);
    return 0;
}