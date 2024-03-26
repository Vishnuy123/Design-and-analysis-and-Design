#include <stdio.h>
#include <limits.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}
int optimal_bst(int keys[], int freq[], int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = freq[i];
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; k++) {
                int cost = ((k > i) ? dp[i][k - 1] : 0) +
                           ((k < j) ? dp[k + 1][j] : 0) +
                           ((k < n) ? freq[k] : 0);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Optimal cost of BST: %d\n", optimal_bst(keys, freq, n));

    return 0;
}

