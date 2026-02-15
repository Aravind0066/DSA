// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
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

struct Node* removeZeroCoefficients(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        
        if (current->coeff == 0) {
            if (prev == NULL) {
                head = next;
            } else {
                prev->next = next;
            }
            free(current);
        } else {
            prev = current;
        }
        current = next;
    }
    
    return head;
}

void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->coeff);
        temp = temp->next;
    }
}

int main() {
    struct Node* poly = NULL;
    int n, coeff;
    
    scanf("%d", &n);
    for (int i = n; i >= 0; i--) {
        scanf("%d", &coeff);
        insertEnd(&poly, coeff, i);
    }
    
    poly = removeZeroCoefficients(poly);
    displayPolynomial(poly);
    
    return 0;
}