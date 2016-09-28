#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <assert.h>

#include "clz.h"

#define ITERA_START 0
#define ITERA_END 1000000
#define LEVEL 1

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec - t2.tv_nsec < 0) {
        diff.tv_sec = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main(int argc, char const *argv[])
{
    FILE *output;

    struct timespec start, end;

    uint32_t i = 0;
    int leading_zero = 0;
    double compute_time;

    for (i = ITERA_START; i < ITERA_END; i+=LEVEL) {
#if defined(RECURSIVE)
        clock_gettime(CLOCK_REALTIME, &start);
        leading_zero = recursive(i, 32);
        clock_gettime(CLOCK_REALTIME, &end);
        compute_time = diff_in_second(start, end);

        assert(leading_zero == iteration(i) && "recursive error\n");

        output = fopen("txt_recursive.txt", "a");
        fprintf(output, "%d leading_zero time %d %0.9lf\n", i, leading_zero, compute_time);
#endif

#if defined(ITERATION)
        clock_gettime(CLOCK_REALTIME, &start);
        leading_zero = iteration(i);
        clock_gettime(CLOCK_REALTIME, &end);
        compute_time = diff_in_second(start, end);

        output = fopen("txt_iteration.txt", "a");
        fprintf(output, "%d leading_zero time %d %0.9lf\n", i, leading_zero, compute_time);
#endif

#if defined(BINARY_SEARCH)
        clock_gettime(CLOCK_REALTIME, &start);
        leading_zero = binary_search(i);
        clock_gettime(CLOCK_REALTIME, &end);
        compute_time = diff_in_second(start, end);

        assert(leading_zero == iteration(i) && "binary error\n");

        output = fopen("txt_binary_search.txt", "a");
        fprintf(output, "%d leading_zero time %d %0.9lf\n", i, leading_zero, compute_time);
#endif

#if defined(BYTE_SHIFT)
        clock_gettime(CLOCK_REALTIME, &start);
        leading_zero = byte_shift(i);
        clock_gettime(CLOCK_REALTIME, &end);
        compute_time = diff_in_second(start, end);

        assert(leading_zero == iteration(i) && "byte error\n");

        output = fopen("txt_byte_shift.txt", "a");
        fprintf(output, "%d leading_zero time %d %0.9lf\n", i, leading_zero, compute_time);
#endif

#if defined(HARLEY_ALGORITHM)
        clock_gettime(CLOCK_REALTIME, &start);
        leading_zero = harley_algorithm(i);
        clock_gettime(CLOCK_REALTIME, &end);
        compute_time = diff_in_second(start, end);

        assert(leading_zero == iteration(i) && "harley error\n");

        output = fopen("txt_harley_algorighm.txt", "a");
        fprintf(output, "%d leading_zero time %d %0.9lf\n", i, leading_zero, compute_time);
#endif


        fclose(output);
    }

    return 0;
}
