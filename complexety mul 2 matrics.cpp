#include <stdio.h>
#include <time.h>
#define SIZE 100 
void multiplyMatrix(int mat1[][SIZE], int mat2[][SIZE], int res[][SIZE], int m, int n, int p) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            res[i][j] = 0;
            for (k = 0; k < n; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main() {
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE], res[SIZE][SIZE];
    int m, n, p, i, j;

    printf("Enter the number of rows and columns for the first matrix (m n): ");
    scanf("%d %d", &m, &n);
    printf("Enter the number of columns for the second matrix (p): ");
    scanf("%d", &p);
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
	clock_t start_time = clock();

    multiplyMatrix(mat1, mat2, res, m, n, p);

    clock_t end_time = clock(); 

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Resultant matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
	printf("Time taken for matrix multiplication: %f seconds\n", time_taken);
	return 0;
}

