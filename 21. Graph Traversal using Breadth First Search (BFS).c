#include <stdio.h>
#define MAX 5

int adj[MAX][MAX];
int visited[MAX] = {0};
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if(rear == MAX-1) printf("Queue is full\n");
    else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = v;
    }
}

int dequeue() {
    int item;
    if(front == -1 || front > rear) {
        return -1;
    }
    item = queue[front];
    front++;
    return item;
}

void bfs(int v) {
    int i;
    enqueue(v);
    visited[v] = 1;
    while((v = dequeue()) != -1) {
        printf("%d ", v);
        for(i = 0; i < MAX; i++) {
            if(adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    printf("BFS traversal starting from vertex 0: ");
    bfs(0);
    printf("\n");
    return 0;
}
