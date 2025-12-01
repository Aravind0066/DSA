// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->left = temp->right = NULL;
    return temp;
}

void printInorderOdd(struct Node* node) {
    if (node == NULL)
        return;

    printInorderOdd(node->left);

    if (node->data % 2 != 0)
        printf("%d ", node->data);

    printInorderOdd(node->right);
}

struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        struct Node* temp = newNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = NULL;
    root = insertLevelOrder(arr, root, 0, n);

    printInorderOdd(root);
    return 0;
}