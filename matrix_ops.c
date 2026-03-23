#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_matrix(int r, int c, double m[r][c]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%lf", &m[i][j]);
}

void print_matrix(int r, int c, double m[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%8.2f ", m[i][j]);
        printf("\n");
    }
}

int find_saddle_point(int r, int c, double m[r][c], double *val, int *row, int *col) {
    for (int i = 0; i < r; i++) {
        double minRow = m[i][0];
        int minCol = 0;
        for (int j = 1; j < c; j++) {
            if (m[i][j] < minRow) { minRow = m[i][j]; minCol = j; }
        }
        int isSaddle = 1;
        for (int k = 0; k < r; k++) {
            if (m[k][minCol] > minRow) { isSaddle = 0; break; }
        }
        if (isSaddle) {
            *val = minRow; *row = i; *col = minCol;
            return 1;
        }
    }
    return 0;
}

int is_magic_square(int n, double m[n][n]) {
    if (n < 2) return 0;
    double sum = 0;
    for (int j = 0; j < n; j++) sum += m[0][j];
    for (int i = 1; i < n; i++) {
        double s = 0;
        for (int j = 0; j < n; j++) s += m[i][j];
        if (fabs(s - sum) > 1e-6) return 0;
    }
    for (int j = 0; j < n; j++) {
        double s = 0;
        for (int i = 0; i < n; i++) s += m[i][j];
        if (fabs(s - sum) > 1e-6) return 0;
    }
    double s = 0;
    for (int i = 0; i < n; i++) s += m[i][i];
    if (fabs(s - sum) > 1e-6) return 0;
    s = 0;
    for (int i = 0; i < n; i++) s += m[i][n - 1 - i];
    if (fabs(s - sum) > 1e-6) return 0;
    return 1;
}

int inverse_2x2(double m[2][2], double inv[2][2]) {
    double det = m[0][0]*m[1][1] - m[0][1]*m[1][0];
    if (fabs(det) < 1e-9) return 0;
    inv[0][0] =  m[1][1] / det;
    inv[0][1] = -m[0][1] / det;
    inv[1][0] = -m[1][0] / det;
    inv[1][1] =  m[0][0] / det;
    return 1;
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and cols of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols of second matrix: ");
    scanf("%d %d", &r2, &c2);

    double a[r1][c1], b[r2][c2];
    printf("Enter elements of first matrix:\n");
    read_matrix(r1, c1, a);
    printf("Enter elements of second matrix:\n");
    read_matrix(r2, c2, b);

    if (r1 == r2 && c1 == c2) {
        printf("\nSum of matrices:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++)
                printf("%8.2f ", a[i][j] + b[i][j]);
            printf("\n");
        }
    } else {
        printf("Cannot add matrices with different dimensions.\n");
    }

    if (r1 == 2 && c1 == 2) {
        double inv[2][2];
        if (inverse_2x2(a, inv)) {
            printf("\nInverse of first 2x2 matrix:\n");
            print_matrix(2, 2, inv);
        } else {
            printf("\nFirst matrix is singular; inverse not available.\n");
        }
    } else {
        printf("\nInverse is implemented only for 2x2 first matrix.\n");
    }

    if (r1 == c1) {
        double saddleVal;
        int sr, sc;
        if (find_saddle_point(r1, c1, a, &saddleVal, &sr, &sc)) {
            printf("\nSaddle point in first matrix: value %.2f at (%d, %d)\n", saddleVal, sr, sc);
        } else {
            printf("\nNo saddle point in first matrix.\n");
        }

        if (is_magic_square(r1, a)) {
            printf("\nFirst matrix is a magic square.\n");
        } else {
            printf("\nFirst matrix is not a magic square.\n");
        }
    } else {
        printf("\nSaddle point and magic square checks require square matrix.\n");
    }

    return 0;
}
