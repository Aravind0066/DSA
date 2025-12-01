// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(char data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperand(char c)
{
    return isdigit(c);
}

struct TreeNode *buildExpressionTree(char *exprsn, int *index)
{
    if (*index >= strlen(exprsn))
        return NULL;

    char token = exprsn[(*index)++];
    struct TreeNode *node = createNode(token);

    if (isOperand(token))
        return node;

    node->left = buildExpressionTree(exprsn, index);
    node->right = buildExpressionTree(exprsn, index);

    return node;
}

double evaluateExpressionTree(struct TreeNode *root)
{
    if (root == NULL)
        return -1;

    if (isOperand(root->data))
        return root->data - '0';

    double leftValue = evaluateExpressionTree(root->left);
    double rightValue = evaluateExpressionTree(root->right);

    switch (root->data)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    }

    return 0;
}

int main()
{
    char exprsn[100];
    scanf("%s", exprsn);

    int index = 0;
    struct TreeNode *root = buildExpressionTree(exprsn, &index);

    printf("Result: %.0f\n", evaluateExpressionTree(root));

    return 0;
}