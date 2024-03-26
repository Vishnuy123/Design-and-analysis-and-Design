#include <stdio.h>

void findFactors(int n, int divisor) {
    if (divisor > n)
        return;
    
    if (n % divisor == 0)
        printf("%d ", divisor);
    
    findFactors(n, divisor + 1);
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Factors of %d are: ", n);
    findFactors(n, 1);

    return 0;
}

