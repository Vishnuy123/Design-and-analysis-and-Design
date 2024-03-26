#include <stdio.h>
unsigned long long binomialCoefficient(int n, int k) {
    unsigned long long C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}
int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if (k < 0 || k > n) {
        printf("Invalid input: k should be between 0 and n.\n");
        return 1;
    }
	printf("Binomial coefficient of %d choose %d is: %llu\n", n, k, binomialCoefficient(n, k));
    return 0;
}

