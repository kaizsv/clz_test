#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE *fp = fopen("txt_recursive.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    int i = 0, d;
    double sum_recursive = 0.0, txt_recursive;
    for (i = 0; i < 1000000; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%d %lf\n", &d, &txt_recursive);
        sum_recursive += txt_recursive;
    }
    fclose(fp);

	/* iteration */
    fp = fopen("txt_iteration.txt", "r");
    if (!fp) {
        printf("ERROR opening input file opt.txt\n");
        exit(0);
    }
    double sum_iteration = 0.0, txt_iteration;
    for (i = 0; i < 1000000; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%d %lf\n", &d, &txt_iteration);
		sum_iteration += txt_iteration;
    }

	/* binary_search */
    fp = fopen("txt_binary_search.txt", "r");
    if (!fp) {
        printf("ERROR opening input file opt.txt\n");
        exit(0);
    }
    double sum_binary_search = 0.0, txt_binary_search;
    for (i = 0; i < 1000000; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%d %lf\n", &d, &txt_binary_search);
		sum_binary_search += txt_binary_search;
    }

	/* byte_shift */
    fp = fopen("txt_byte_shift.txt", "r");
    if (!fp) {
        printf("ERROR opening input file opt.txt\n");
        exit(0);
    }
    double sum_byte_shift = 0.0, txt_byte_shift;
    for (i = 0; i < 1000000; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%d %lf\n", &d, &txt_byte_shift);
		sum_byte_shift += txt_byte_shift;
    }

	/* harley_algorighm */
    fp = fopen("txt_harley_algorighm.txt", "r");
    if (!fp) {
        printf("ERROR opening input file opt.txt\n");
        exit(0);
    }
    double sum_harley_algorighm = 0.0, txt_harley_algorighm;
    for (i = 0; i < 1000000; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%d %lf\n", &d, &txt_harley_algorighm);
		sum_harley_algorighm += txt_harley_algorighm;
    }

    fprintf(output, "recursive %0.9lf\n", sum_recursive / 1000000.0);
    fprintf(output, "iteration %0.9lf\n", sum_iteration / 1000000.0);
    fprintf(output, "binaryh %0.9lf\n", sum_binary_search / 1000000.0);
    fprintf(output, "byte %0.9lf\n", sum_byte_shift / 1000000.0);
    fprintf(output, "harley %0.9lf", sum_harley_algorighm / 1000000.0);


    fclose(output);
    fclose(fp);
    return 0;
}
