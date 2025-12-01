// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return head;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

struct Node* deleteAfterValue(struct Node* head, int X) {
    if (head == NULL || head->next == head)
        return head;

    struct Node* temp = head;
    int found = 0;

    do {
        if (temp->data == X) {
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found) {
        printf("Value %d not found.\n", X);
        return head;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    return head;
}

void printList(struct Node* head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    struct Node* temp = head;
    printf("%d -> ", temp->data);
    temp = temp->next;
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int N, data, X;
    struct Node* head = NULL;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printList(head);

    scanf("%d", &X);

    head = deleteAfterValue(head, X);

    printList(head);

    return 0;
}