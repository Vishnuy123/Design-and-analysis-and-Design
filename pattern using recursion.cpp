#include <stdio.h>
void printPattern(int n, int i, int j) {
    if (i > n) {
        return;
    }
    if (j > i) {
        printf("\n");
        printPattern(n, i + 1, 1);
        return;
    }
    printf("%d ", j);
    printPattern(n, i, j + 1);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPattern(n, 1, 1);

    return 0;
}

