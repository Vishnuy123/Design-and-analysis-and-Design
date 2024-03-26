#include <stdio.h>
#include <stdbool.h>

#define N 8 
#define MAX_SOLUTIONS 8
void printSolution(int board[N][N]) {
    static int count = 1;
    printf("Solution %d:\n", count++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
int solveNQueens(int board[N][N], int col, int solutionsFound) {
    if (col >= N) {
        printSolution(board);
        return solutionsFound + 1; 
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solutionsFound = solveNQueens(board, col + 1, solutionsFound);
            if (solutionsFound >= MAX_SOLUTIONS) {
                return solutionsFound;
            }
            board[i][col] = 0; 
        }
    }

    return solutionsFound; 
}

void nQueens() {
    int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0} };

    int solutionsFound = 0;
    solutionsFound = solveNQueens(board, 0, solutionsFound);
    if (solutionsFound < MAX_SOLUTIONS) {
        printf("Less than 8 solutions found.\n");
    }
}

int main() {
    nQueens();
    return 0;
}
