#include <stdio.h>
#define MAX 5

int adj[MAX][MAX];
int visited[MAX] = {0};

void dfs(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for(i = 0; i < MAX; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }
    adj[0][1] = 1; adj[0][2] = 1;
    adj[1][3] = 1; adj[1][4] = 1;
    adj[2][4] = 1;

    printf("DFS traversal starting from vertex 0: ");
    dfs(0);
    printf("\n");
    return 0;
}
