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
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data >= root->data) {
        root->right = insert(root->right, data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    }

    return root;
}

void levelOrderTraversal(struct Node* root, int level, int* product, int* isFirst) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        printf("%d ", root->data);

        if (*isFirst == 1) {
            *product *= root->data;
            *isFirst = 0;
        }
    } else {
        levelOrderTraversal(root->left, level - 1, product, isFirst);
        levelOrderTraversal(root->right, level - 1, product, isFirst);
    }
}

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return ((leftHeight > rightHeight) ? leftHeight : rightHeight)+1;
}

int main() {
    int N;
    scanf("%d", &N);
    int values[N+1];
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &values[i]);
    }

    struct Node* root = NULL;

    for (int i = 1; i <= N; i++) {
        root = insert(root, values[i]);
    }

    int treeHeight = height(root);

    int product = 1;

    for (int level = 1; level <= treeHeight; level++) {
        int isFirst = 1;
        levelOrderTraversal(root, level, &product, &isFirst);
    }

    printf("\n");
    printf("%d\n", product);

    return 0;
}