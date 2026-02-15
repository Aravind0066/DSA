// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* s) {
    s->top = NULL;
}

int isEmpty(struct Stack* s) {
    return s->top == NULL;
}

void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}

void displayStack(struct Stack* s) {
    struct Node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getSum(struct Stack* s) {
    int sum = 0;
    struct Node* temp = s->top;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int getMax(struct Stack* s) {
    if (isEmpty(s)) return 0;
    int max = 0;
    struct Node* temp = s->top;
    while (temp != NULL) {
        if (temp->data > max) max = temp->data;
        temp = temp->next;
    }
    return max;
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(&stack, value);
    }

    displayStack(&stack);

    int sum = getSum(&stack);
    int max = getMax(&stack);

    printf("%d\n", sum);
    printf("%d\n", max);

    return 0;
}