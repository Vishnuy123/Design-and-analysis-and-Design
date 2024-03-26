#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

typedef struct {
    int weight;
    int value;
} Item;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int containerLoader(int n, int capacity, Item items[]) {
    int i, w;
    int K[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i - 1].weight <= w)
                K[i][w] = max(items[i - 1].value + K[i - 1][w - items[i - 1].weight], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][capacity];
}

int main() {
    int n, capacity, i;
    Item items[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the container: ");
    scanf("%d", &capacity);

    printf("Enter weights and values of %d items:\n", n);
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    int max_value = containerLoader(n, capacity, items);

    printf("The maximum value that can be loaded into the container is: %d\n", max_value);

    return 0;
}

