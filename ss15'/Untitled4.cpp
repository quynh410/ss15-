#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

int hasCycle(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            if (!visited[i] && hasCycle(i)) {
                return 1;
            } else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[v] = 0;
    return 0;
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
        recStack[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        printf("Nhap canh %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    int cycleExists = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && hasCycle(i)) {
            cycleExists = 1;
            break;
        }
    }

    if (cycleExists) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }

    return 0;
}
