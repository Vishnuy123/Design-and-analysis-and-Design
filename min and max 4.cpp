#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int size;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    int *numbers = (int*)malloc(size * sizeof(int)); 
    
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the elements separated by spaces: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    int min = INT_MAX;
    int max = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    
    free(numbers); 
    return 0;
}

