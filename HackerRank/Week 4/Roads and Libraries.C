#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 100005

typedef struct Node {
    int city;
    struct Node* next;
} Node;

Node* adj[MAX];
bool visited[MAX];

void addEdge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->city = v;
    node->next = adj[u];
    adj[u] = node;
}

int dfs(int u) {
    visited[u] = true;
    int count = 1;
    Node* temp = adj[u];
    while(temp != NULL) {
        int v = temp->city;
        if(!visited[v])
            count += dfs(v);
        temp = temp->next;
    }
    return count;
}

long roadsAndLibraries(int n, int c_lib, int c_road, int cities_rows, int cities_columns, int** cities) {
    for(int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = false;
    }

    for(int i = 0; i < cities_rows; i++) {
        int u = cities[i][0];
        int v = cities[i][1];
        addEdge(u, v);
        addEdge(v, u);
    }

    long totalCost = 0;

    if(c_road >= c_lib) return (long)n * c_lib;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            int size = dfs(i);
            totalCost += (long)c_lib + (long)(size - 1) * c_road;
        }
    }

    return totalCost;
}

int main() {
    int q;
    scanf("%d", &q);

    for(int qi = 0; qi < q; qi++) {
        int n, m, c_lib, c_road;
        scanf("%d %d %d %d", &n, &m, &c_lib, &c_road);

        int** cities = malloc(m * sizeof(int*));
        for(int i = 0; i < m; i++) {
            cities[i] = malloc(2 * sizeof(int));
            scanf("%d %d", &cities[i][0], &cities[i][1]);
        }

        long cost = roadsAndLibraries(n, c_lib, c_road, m, 2, cities);
        printf("%ld\n", cost);

        for(int i = 0; i < m; i++) free(cities[i]);
        free(cities);
    }

    return 0;
}
