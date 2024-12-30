#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int graph[MAX][MAX];
int V;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int E, u, v;
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    printf("Nhap so canh: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        printf("Nhap canh %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    dfs(0);

    int isConnected = 1;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            isConnected = 0;
            break;
        }
    }

    if (isConnected) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }

    return 0;
}
