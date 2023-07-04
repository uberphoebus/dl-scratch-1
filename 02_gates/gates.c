#include <stdio.h>

int and_gate(int x1, int x2);
int nand_gate(int x1, int x2);
int or_gate(int x1, int x2);
int xor_gate(int x1, int x2);

int main(void) {
    printf("[c implementation of gates]\n\n");

    printf("= and gate =\n");
    printf("0 and 0 = %d\n", and_gate(0, 0));   // 0
    printf("0 and 1 = %d\n", and_gate(0, 1));   // 0
    printf("1 and 0 = %d\n", and_gate(1, 0));   // 0
    printf("1 and 1 = %d\n\n", and_gate(1, 1)); // 1

    printf("= nand gate =\n");
    printf("0 nand 0 = %d\n", nand_gate(0, 0));   // 1
    printf("0 nand 1 = %d\n", nand_gate(0, 1));   // 1
    printf("1 nand 0 = %d\n", nand_gate(1, 0));   // 1
    printf("1 nand 1 = %d\n\n", nand_gate(1, 1)); // 0

    printf("= or gate =\n");
    printf("0 or 0 = %d\n", or_gate(0, 0));   // 0
    printf("0 or 1 = %d\n", or_gate(0, 1));   // 1
    printf("1 or 0 = %d\n", or_gate(1, 0));   // 1
    printf("1 or 1 = %d\n\n", or_gate(1, 1)); // 1

    printf("= xor gate =\n");
    printf("0 xor 0 = %d\n", xor_gate(0, 0));   // 0
    printf("0 xor 1 = %d\n", xor_gate(0, 1));   // 1
    printf("1 xor 0 = %d\n", xor_gate(1, 0));   // 1
    printf("1 xor 1 = %d\n\n", xor_gate(1, 1)); // 0

    return 0;
}

int and_gate(int x1, int x2) {
    int x[2] = {x1, x2};
    double w[2] = {0.5, 0.5};
    double b = -0.7;

    double tmp = 0;
    for (int i = 0; i < sizeof(x) / sizeof(int); i++) {
        tmp += x[i] * w[i];
    }
    tmp += b;

    if (tmp <= 0)
        return 0;
    else
        return 1;
}

int nand_gate(int x1, int x2) {
    int x[2] = {x1, x2};
    double w[2] = {-0.5, -0.5};
    double b = 0.7;

    double tmp = 0;
    for (int i = 0; i < sizeof(x) / sizeof(int); i++) {
        tmp += x[i] * w[i];
    }
    tmp += b;

    if (tmp <= 0)
        return 0;
    else
        return 1;
}

int or_gate(int x1, int x2) {
    int x[2] = {x1, x2};
    double w[2] = {0.5, 0.5};
    double b = -0.2;

    double tmp = 0;
    for (int i = 0; i < sizeof(x) / sizeof(int); i++) {
        tmp += x[i] * w[i];
    }
    tmp += b;

    if (tmp <= 0)
        return 0;
    else
        return 1;
}

int xor_gate(int x1, int x2) {
    int s1 = nand_gate(x1, x2);
    int s2 = or_gate(x1, x2);
    int y = and_gate(s1, s2);
    return y;
}