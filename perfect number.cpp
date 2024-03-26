#include <stdio.h>
#include <stdbool.h>
bool isPerfect(int num) {
    if (num <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return false;
    }
    
    int sum = 0;
    
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0)
            sum += i;
    }
    
    return sum == num;
}

int main() {
    int number;
    char choice;
    
    do {
        printf("Enter a positive integer: ");
        if (scanf("%d", &number) != 1) {
            printf("Error: Invalid input.\n");
            return 1;
        }
        
        if (isPerfect(number))
            printf("%d is a perfect number.\n", number);
        else
            printf("%d is not a perfect number.\n", number);
        
        printf("Do you want to check another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("Exiting...\n");
    
    return 0;
}

