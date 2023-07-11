#include <math.h>
#include <stdio.h>

void init_ary(double *ary, int len);
void print_ary(double *ary, int len);
void step_function(double *ary, int len);
void sigmoid_function(double *ary, int len);
void relu_function(double *ary, int len);

    int main(void) {

    double ary[100];
    int len = sizeof(ary) / sizeof(double);

    printf("\n--- init_ary ---");
    init_ary(ary, len);
    print_ary(ary, len);

    printf("\n--- step function ---");
    step_function(ary, len);
    print_ary(ary, len);

    printf("\n--- sigmoid function ---");
    init_ary(ary, len);
    sigmoid_function(ary, len);
    print_ary(ary, len);

    printf("\n--- relu function ---");
    init_ary(ary, len);
    relu_function(ary, len);
    print_ary(ary, len);

    return 0;
}

void init_ary(double *ary, int len) {
    for (int i = 0; i < len; i++) {
        ary[i] = i * 0.1 - 5.0;
    }
}

void print_ary(double *ary, int len) {
    for (int i = 0; i < len; i++) {
        if (i % 20 == 0)
            printf("\n");
        else
            printf("%.2lf ", ary[i]);
    }
    printf("\n");
}

void step_function(double *ary, int len) {
    for (int i = 0; i < len; i++) {
        if (ary[i] > 0)
            ary[i] = 1;
        else
            ary[i] = 0;
    }
}

void sigmoid_function(double *ary, int len) {
    for (int i = 0; i < len; i++) {
        ary[i] = 1 / (1 + exp(-ary[i]));
    }
}

void relu_function(double *ary, int len) {
    for (int i = 0; i < len; i++) {
        if (ary[i] > 0)
            ary[i] = ary[i];
        else
            ary[i] = 0;
    }
}