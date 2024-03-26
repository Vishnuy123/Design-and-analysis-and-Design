#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}
void printFibonacci(int n, int count, int a, int b) {
    if (count < n) {
        printf("%d ", a);
        printFibonacci(n, count + 1, b, a + b);
    }
}
int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of terms should be greater than zero.\n");
        return 1; 
    }
	printf("Fibonacci Series up to %d terms:\n", n);
    printFibonacci(n, 0, 0, 1);
	return 0;
}

