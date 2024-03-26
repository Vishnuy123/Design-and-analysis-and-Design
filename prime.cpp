#include <stdio.h>

int isPrime(int num, int i) {
    if (i == 1) {
        return 1;
    } else {
        if (num % i == 0) {
            return 0;
        } else {
            return isPrime(num, i - 1);
        }
    }
}

void generatePrimes(int n, int i) {
    if (i <= n) {
        if (isPrime(i, i / 2)) {
            printf("%d ", i);
        }
        generatePrimes(n, i + 1);
    }
}

int main() {
    int limit;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are: ", limit);
    generatePrimes(limit, 2); // Start from 2
    printf("\n");

    return 0;
}

