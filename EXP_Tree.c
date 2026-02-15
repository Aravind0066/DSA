#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Node {
    char data[MAX_SIZE];
    struct Node* left;
    struct Node* right;
};

int isOperand(char c) {
    return isalnum(c); // digit or letter
}

struct Node* createNode(const char data[MAX_SIZE]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* postfixToTree(const char* postfix) {
    struct Node* stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            char op[2] = {postfix[i], '\0'};
            stack[++top] = createNode(op);
        } else {
            struct Node* right = stack[top--];
            struct Node* left = stack[top--];
            char op[2] = {postfix[i], '\0'};
            struct Node* temp = createNode(op);
            temp->left = left;
            temp->right = right;
            stack[++top] = temp;
        }
    }

    return stack[top];
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%s", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void freeTree(struct Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char postfix[MAX_SIZE];
    if (scanf("%s", postfix) != 1) return 0;

    struct Node* root = postfixToTree(postfix);

    preOrder(root);
    printf("\n");

    freeTree(root);

    return 0;
}
