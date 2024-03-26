#include <stdio.h>
#include <math.h>
int countDigits(int num) {
    if (num == 0)
        return 0;
    else
        return 1 + countDigits(num / 10);
}
int isArmstrong(int num, int n) {
    if (num == 0)
        return 0;
    else
        return pow(num % 10, n) + isArmstrong(num / 10, n);
}

int main() {
    int number, sum = 0, digits;

    printf("Enter a number: ");
    scanf("%d", &number);

    digits = countDigits(number);

    sum = isArmstrong(number, digits);

    if (sum == number)
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);

    return 0;
}

