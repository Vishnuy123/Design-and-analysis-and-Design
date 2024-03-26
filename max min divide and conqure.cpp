#include <stdio.h>
struct Pair {
    int min;
    int max;
};
struct Pair findMaxMin(int arr[], int low, int high) {
    struct Pair minmax, left_minmax, right_minmax;
    int mid;
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.min = arr[high];
            minmax.max = arr[low];
        } else {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        return minmax;
    }
    mid = (low + high) / 2;
    left_minmax = findMaxMin(arr, low, mid);
    right_minmax = findMaxMin(arr, mid + 1, high);
    if (left_minmax.min < right_minmax.min)
        minmax.min = left_minmax.min;
    else
        minmax.min = right_minmax.min;

    if (left_minmax.max > right_minmax.max)
        minmax.max = left_minmax.max;
    else
        minmax.max = right_minmax.max;

    return minmax;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    struct Pair minmax = findMaxMin(arr, 0, arr_size - 1);

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);
    
    return 0;
}

