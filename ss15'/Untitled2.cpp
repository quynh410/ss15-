#include<stdio.h>
#define V 5
int visited[V];
int graph[V][V];
//ham duyet theo chieu sau
void DFS(int v, int n) {
	printf("%d", v);
	visited[v] = 1;
	for(int i =0; i < n; i++) {
		if(visited[i] == 0 && graph[v][i] == 1) {
			DFS(i,n);
		}
	}
}
int main () {
	int visited[V];
	int n, u, v, edges, start;
	printf("nhap vao so dinh: ");
	scanf("%d",&n);

	printf("nhap vao so canh: ");
	scanf("%d",&edges);

	printf("nhap cac dinh (dinh u v): ");
	for(int i =0; i< edges; i++) {
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	printf("nhap vao dinh bat dau duyet: ");
	scanf("%d",&start);
	DFS(start,n);
	return 0;
}
 