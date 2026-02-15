// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data > root->data)
        root->right = insert(root->right, data);
    else if (data <= root->data)
        root->left = insert(root->left, data);

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int sumNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return root->data + sumNodes(root->right) + sumNodes(root->left);
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->right) + countNodes(root->left);
}

void deleteGreaterThanAverage(struct Node** root, int avg) {
    if (*root == NULL)
        return;

    deleteGreaterThanAverage(&((*root)->right), avg);
    deleteGreaterThanAverage(&((*root)->left), avg);

    if (*root && (*root)->data > avg) {
        struct Node* temp = *root;
        if ((*root)->left == NULL) {
            *root = (*root)->right;
        } else if ((*root)->right == NULL) {
            *root = (*root)->left;
        } else {
            struct Node* predParent = *root;
            struct Node* pred = (*root)->left;
            while (pred->right != NULL) {
                predParent = pred;
                pred = pred->right;
            }
            (*root)->data = pred->data;
            if (predParent->right == pred)
                predParent->right = pred->left;
            else
                predParent->left = pred->left;
            free(pred);
            return;
        }
        free(temp);
    }
}

int main() {
    struct Node* root = NULL;
    int n, data;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    int sum = sumNodes(root);
    int count = countNodes(root);
    int avg = count ? sum / count : 0;

    deleteGreaterThanAverage(&root, avg);

    inOrderTraversal(root);

    return 0;
}