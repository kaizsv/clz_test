#include <stdio.h>
#include <stdint.h>

#include "clz.h"

int recursive(uint32_t N, int length)
{
    int shift = length >> 1;
    int left = 32 - shift;
    uint32_t MAX = 0xFFFFFFFF;

    uint16_t upper = (N >> shift) & (MAX >> left);
    uint16_t lower = (N & (MAX >> left));

    if (shift == 1) {
        return upper ? 0 : (lower ? 1 : 2);
    }

    return upper ? recursive(upper, shift) : shift + recursive(lower, shift);
}

int iteration(uint32_t N)
{
    int n = 32, c = 16;
    do {
        uint32_t y = N >> c;
        if (y) {
            n -= c;
            N = y;
        }
        c >>= 1;
    } while (c);
    return (n - N);
}

int binary_search(uint32_t N)
{
    if (N == 0) return 32;
    int n = 0;
    if (N <= 0x0000FFFF) {
        n += 16;
        N <<= 16;
    }
    if (N <= 0x00FFFFFF) {
        n += 8;
        N <<= 8;
    }
    if (N <= 0x0FFFFFFF) {
        n += 4;
        N <<= 4;
    }
    if (N <= 0x3FFFFFFF) {
        n += 2;
        N <<= 2;
    }
    if (N <= 0x7FFFFFFF) {
        n += 1;
        N <<= 1;
    }
    return n;
}

int byte_shift(uint32_t N)
{
    if (N == 0) return 32;
    int n = 1;
    if ((N >> 16) == 0) {
        n += 16;
        N <<= 16;
    }
    if ((N >> 24) == 0) {
        n += 8;
        N <<= 8;
    }
    if ((N >> 28) == 0) {
        n += 4;
        N <<= 4;
    }
    if ((N >> 30) == 0) {
        n += 2;
        N <<= 2;
    }
    n = n - (N >> 31);
    return n;
}

int harley_algorithm(uint32_t N)
{
    static int const table[] = {
        32, 31, 0xff, 16, 0xff, 30, 3, 0xff,
        15, 0xff, 0xff, 0xff, 29, 10, 2, 0xff,
        0xff, 0xff, 12, 14, 21, 0xff, 19, 0xff,
        0xff, 28, 0xff, 25, 0xff, 9, 1, 0xff,
        17, 0xff, 4, 0xff, 0xff, 0xff, 11, 0xff,
        13, 22, 20, 0xff, 26, 0xff, 0xff, 18,
        5, 0xff, 0xff, 23, 0xff, 27, 0xff, 6,
        0xff, 24, 7, 0xff, 8, 0xff, 0, 0xff
    };

    N = N | (N >> 1);
    N = N | (N >> 2);
    N = N | (N >> 4);
    N = N | (N >> 8);
    N = N | (N >> 16);

    N = (N << 3) - N;
    N = (N << 8) - N;
    N = (N << 8) - N;
    N = (N << 8) - N;

    return table[N >> 26];

}
