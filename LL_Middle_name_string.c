// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char name[101];
    struct Node* next;
};

struct Node* createNode(char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head, char* name) {
    struct Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
struct Node* findMiddle(struct Node* head) {
    int len = getLength(head);
    int mid = len / 2;   
    for (int i = 0; i < mid; i++) {
        head = head->next;
    }
    return head;
}
int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    char name[101];

    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        append(&head, name);
    }

    struct Node* middle = findMiddle(head);
    if (middle != NULL) {
        printf("%s\n", middle->name);
    }

    return 0;
}