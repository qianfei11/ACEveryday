#include <stdio.h>
#include <stdint.h>
#define DELTA 0x9e3779b9

void encrypt(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {
    uint32_t v0 = v[0], v1 = v[1], sum = 0;
    for(int i = 0; i < num_rounds; i++) {
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
        sum += DELTA;
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum >> 11) & 3])
    }
    v[0] = v0;
    v[1] = v1;
}

void decrypt(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {
    uint32_t v0 = v[0], v1 = v[1], sum = DELTA * num_rounds;
    for(int i = 0; i < num_rounds; i++) {
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum >> 1) & 3]);
        sum -= DELTA;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
    }
    v[0] = v0;
    v[1] = v1;
}

int main() {
    uint32_t v[2] = {1, 2};
    uint32_t const k[4] = {2, 2, 3, 4};
    unsigned int r = 32;
    printf("origin: %u %u\n", v[0], v[1]);
    encrypt(r, v, k);
    printf("encrypt: %u %u\n", v[0], v[1]);
    decrypt(r, v, k);
    printf("decrypt: %u %u\n", v[0], v[1]);
    return 0;
}