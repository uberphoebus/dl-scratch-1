#include <stdio.h>

void matrix_multipy(int (*pa)[2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", pa[i][j]);
        }
    }
}

int main(void) {
    int a1[2][2] = {{1, 2}, {3, 4}};
    int b1[2][2] = {{5, 6}, {7, 8}};

    int a2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b2[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    int res1[2][2];
    matrix_multipy(a1);

    return 0;
}