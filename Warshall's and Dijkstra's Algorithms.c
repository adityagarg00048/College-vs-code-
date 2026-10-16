#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define INF 99999

// Function to print a 2D matrix
void printMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// ==========================================
// 1. WARSHALL'S ALGORITHM (Transitive Closure)
// ==========================================
void warshall(int graph[MAX][MAX], int n) {
    int reach[MAX][MAX];
    
    // Initialize reachability matrix with the original graph representation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    // Update reachability using intermediate vertices k
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printf("\n--- Warshall's Algorithm (Transitive Closure) ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

// ==========================================
// 2. DIJKSTRA'S ALGORITHM (Single-Source Shortest Path)
// ==========================================
int minDistance(int dist[], bool sptSet[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    bool sptSet[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\n--- Dijkstra's Algorithm (Shortest Paths from Source %d) ---\n", src);
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    int n = 4;
    
    // Example adjacency matrix for reachability / Warshall's
    int reachGraph[MAX][MAX] = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {1, 0, 1, 0}
    };

    // Example positively-weighted adjacency matrix for Dijkstra's
    int weightGraph[MAX][MAX] = {
        {0, 4, 0, 0},
        {4, 0, 8, 0},
        {0, 8, 0, 7},
        {0, 0, 7, 0}
    };

    warshall(reachGraph, n);
    dijkstra(weightGraph, n, 0);

    return 0;
}
