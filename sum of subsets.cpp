#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int set[MAX_SIZE];
int subset[MAX_SIZE];
bool found = false;

void subsetSum(int set[], int subset[], int n, int subSize, int total, int nodeCount, int target) {
    if (total == target) {
        printf("Subset found: ");
        for (int i = 0; i < subSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        found = true;
        return;
    }

    if (nodeCount == n || total > target) {
        return;
    }

    subset[subSize] = set[nodeCount];
    subsetSum(set, subset, n, subSize + 1, total + set[nodeCount], nodeCount + 1, target);
    subsetSum(set, subset, n, subSize, total, nodeCount + 1, target);
}

int main() {
    int n, target;

    printf("Enter the size of the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    subsetSum(set, subset, n, 0, 0, 0, target);

    if (!found) {
        printf("No subset found with the given sum.\n");
    }

    return 0;
}

