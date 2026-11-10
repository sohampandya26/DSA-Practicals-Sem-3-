/*
 * Practical 14 : Robot exploring a maze - Depth First Search (DFS)
 * The maze is a graph: locations = vertices, paths = edges (undirected).
 * Representation : adjacency matrix        Time: O(V^2)   Space: O(V^2)
 *
 * Input format:
 *   V E
 *   u v        (E lines, locations numbered 0..V-1)
 *   start treasure
 */
#include <stdio.h>

#define MAX_V 20

static int adj[MAX_V][MAX_V];
static int visited[MAX_V];
static int V, order[MAX_V], visitedCount = 0, treasure = -1, treasureFound = 0;

void dfs(int u)
{
    visited[u] = 1;
    order[visitedCount++] = u;
    printf("Robot visits location %d%s\n", u, u == treasure ? "   <-- TREASURE FOUND!" : "");
    if (u == treasure) treasureFound = 1;

    for (int v = 0; v < V; v++)           /* go as deep as possible first */
        if (adj[u][v] && !visited[v])
            dfs(v);
    /* returning from the recursion == robot backtracks */
}

int main(void)
{
    int E, u, v, start;

    printf("Enter number of locations and paths: ");
    if (scanf("%d %d", &V, &E) != 2 || V < 1 || V > MAX_V || E < 0) { printf("Invalid input.\n"); return 1; }

    printf("Enter %d paths (u v):\n", E);
    for (int i = 0; i < E; i++) {
        if (scanf("%d %d", &u, &v) != 2 || u < 0 || v < 0 || u >= V || v >= V) { printf("Invalid path.\n"); return 1; }
        adj[u][v] = adj[v][u] = 1;
    }

    printf("Enter entrance location and treasure location: ");
    if (scanf("%d %d", &start, &treasure) != 2 || start < 0 || start >= V) { printf("Invalid location.\n"); return 1; }

    printf("\n--- Maze adjacency matrix ---\n   ");
    for (int j = 0; j < V; j++) printf("%2d ", j);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%2d ", i);
        for (int j = 0; j < V; j++) printf("%2d ", adj[i][j]);
        printf("\n");
    }

    printf("\n--- DFS exploration ---\n");
    dfs(start);

    printf("\nOrder of visit: ");
    for (int i = 0; i < visitedCount; i++) printf("%d%s", order[i], i < visitedCount - 1 ? " -> " : "\n");
    printf(treasureFound ? "Treasure was found at location %d.\n" : "Treasure at location %d is not reachable from the entrance.\n", treasure);

    if (visitedCount < V) {
        printf("Unreachable locations:");
        for (int i = 0; i < V; i++) if (!visited[i]) printf(" %d", i);
        printf("\n");
    }
    return 0;
}
