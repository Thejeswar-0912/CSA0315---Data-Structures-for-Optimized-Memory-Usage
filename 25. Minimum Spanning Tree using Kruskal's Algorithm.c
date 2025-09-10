#include <stdio.h>
#include <stdlib.h>
#define V 5

int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskalMST(int cost[V][V]) {
    int mincost = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n", edge_count++, a, b, min);
        mincost += min;
    }
    printf("Minimum cost= %d \n", mincost);
}

int main() {
    int cost[V][V];
    int i, j;
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            if(i==j)
                cost[i][j] = 0;
            else
                cost[i][j] = 999;
        }
    }
    cost[0][1] = 2; cost[0][3] = 6;
    cost[1][0] = 2; cost[1][2] = 3; cost[1][3] = 8; cost[1][4] = 5;
    cost[2][1] = 3; cost[2][4] = 7;
    cost[3][0] = 6; cost[3][1] = 8; cost[3][4] = 9;
    cost[4][1] = 5; cost[4][2] = 7; cost[4][3] = 9;

    kruskalMST(cost);
    return 0;
}
