#include <stdio.h>
void get_c_largest(int arr[], int n, int c) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("The %d largest elements are: ", c);
    for (int i = 0; i < c; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, c;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of c: ");
    scanf("%d", &c);

    get_c_largest(arr, n, c);
    return 0;
}

