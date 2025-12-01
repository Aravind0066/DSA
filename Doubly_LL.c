// You are using GCC
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int patientID;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->patientID = id;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head, int id) {
    struct Node* newNode = createNode(id);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->patientID);
        head = head->next;
    }
    printf("\n");
}
int main() {
    int n, id;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        append(&head, id);
    }
    deleteAtBeginning(&head);
    display(head);

    return 0;
}