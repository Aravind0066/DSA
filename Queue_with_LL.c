// You are using GCC
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue q; 

void initQueue() {
    q.front = q.rear = NULL;
}

int isEmpty() {
    return q.front == NULL && q.rear == NULL;
}

void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q.front == NULL) {
        q.front = q.rear = newNode;
        return;
    }

    q.rear->next = newNode;
    q.rear = newNode;
}

int dequeue() {
    if (isEmpty()) {
        return -1;
    }

    Node* temp = q.front;
    int data = temp->data;
    q.front = q.front->next;

    free(temp);
    return data;
}

int isSeen(int seen[], int value, int size) {
    for (int i = 0; i < size; i++) {
        if (seen[i] == value) {
            return 1;
        }
    }
    return 0;
}

void removeDuplicates() {
    if (isEmpty()) {
        return;
    }

    int seen[MAX];
    int seenSize = 0;

    Node* current = q.front;
    Node* prev = NULL;

    while (current != NULL) {
        if (isSeen(seen, current->data, seenSize)) {
            Node* temp = current;
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                q.front = current->next;
            }
            current = current->next;
            free(temp);
        } else {
            seen[seenSize++] = current->data;
            prev = current;
            current = current->next;
        }
    }
}

void printQueue() {
    Node* temp = q.front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int numElements;
    initQueue();

    scanf("%d", &numElements);

    for (int i = 0; i < numElements; ++i) {
        int element;
        scanf("%d", &element);
        enqueue(element);
    }

    removeDuplicates();
    printQueue();

    return 0;
}