#include <stdio.h>
#include <stdlib.h>

void matrix_multiplication(int **m1, int **m2, int **result, int r1, int c1,
                           int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
int main(void) {

    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    int r1 = sizeof(a) / sizeof(a[0]);
    int c1 = sizeof(a[0]) / sizeof(a[0][0]);
    int r2 = sizeof(b) / sizeof(b[0]);
    int c2 = sizeof(b[0]) / sizeof(b[0][0]);

    int **result = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        result[i] = (int *)malloc(c2 * sizeof(int));
    }

    matrix_multiplication(a, b, result, r1, c1, r2, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
