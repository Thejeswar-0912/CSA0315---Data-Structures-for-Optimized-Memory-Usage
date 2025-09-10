#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void init() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}
void insert(int value) {
    int key = value % SIZE;
    if (hashTable[key] == -1) {
        hashTable[key] = value;
    } else {
        printf("Collision: %d has to be moved\n", value);
        for (int i = 1; i < SIZE; i++) {
            int newKey = (key + i) % SIZE;
            if (hashTable[newKey] == -1) {
                hashTable[newKey] = value;
                return;
            }
        }
    }
}
void display() {
    for (int i = 0; i < SIZE; i++)
        printf("arr[%d] = %d\n", i, hashTable[i]);
}
int main() {
    init();
    insert(10);
    insert(20);
    insert(5);
    insert(15); 
    display();
    return 0;
}
