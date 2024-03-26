#include <stdio.h>
#include <limits.h>

#define V 4 


#define N 4

#define INF INT_MAX


int tsp(int graph[][V], int mask, int pos, int dp[][N]) {
   
    if (mask == (1 << V) - 1) {
        return graph[pos][0]; 
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int min_cost = INF;
    for (int city = 0; city < V; city++) {
        if ((mask & (1 << city)) == 0) { 
            int new_cost = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp);
            min_cost = (new_cost < min_cost) ? new_cost : min_cost;
        }
    }
    return dp[mask][pos] = min_cost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[1 << N][N];
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    int min_cost = tsp(graph, 1, 0, dp);

    printf("Minimum cost for TSP: %d\n", min_cost);

    return 0;
}

