#include <stdio.h>
#include <stdint.h>
#define DELTA 0x9e3779b9

void encrypt(uint32_t* v, uint32_t* k) {
    uint32_t v0 = v[0], v1 = v[1], sum = 0;
    uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
    for(int i = 0; i < 32; i++) {
        sum += DELTA;
        v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
        v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
    }
    v[0] = v0;
    v[1] = v1;
}

void decrypt(uint32_t* v, uint32_t* k) {
    uint32_t v0 = v[0], v1 = v[1], sum = 0xc6ef3720;
    uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
    for(int i = 0; i < 32; i++) {
        v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
        v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
        sum -= DELTA;
    }
}

int main() {
    uint32_t v[2] = {1, 2}, k[4] = {2, 2, 3, 4};
    printf("origin: %u %u\n", v[0], v[1]);
    encrypt(v, k);
    printf("encrypt: %u %u\n", v[0], v[1]);
    decrypt(v, k);
    printf("decrypt: %u %u\n", v[0], v[1]);
    return 0;
}