    // You are using GCC
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    
    #define MAX 100
    
    typedef struct Node {
        char data;
        struct Node *left, *right;
    } Node;
    
    typedef struct {
        Node *items[MAX];
        int top;
    } NodeStack;
    
    typedef struct {
        char items[MAX];
        int top;
    } CharStack;
    
    void initNodeStack(NodeStack *s) { s->top = -1; }
    void pushNode(NodeStack *s, Node *n) { s->items[++s->top] = n; }
    Node* popNode(NodeStack *s) { return s->items[s->top--]; }
    
    void initCharStack(CharStack *s) { s->top = -1; }
    void pushChar(CharStack *s, char c) { s->items[++s->top] = c; }
    char popChar(CharStack *s) { return s->items[s->top--]; }
    char peekChar(CharStack *s) { return s->items[s->top]; }
    int isCharEmpty(CharStack *s) { return s->top < 0; }
    
    Node* newNode(char c) {
        Node *n = (Node*)malloc(sizeof(Node)); 
        n->data = c;
        n->left = n->right = NULL;
        return n;
    }
    
    int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
    
    Node* buildTree(char *expr) {
        NodeStack nodes;
        CharStack ops;
        initNodeStack(&nodes);
        initCharStack(&ops);
    
        for (int i = 0; expr[i]; i++) {
            char c = expr[i];
            if (c == ' ') continue;
            if (isalnum(c)) {
                pushNode(&nodes, newNode(c));
            }
            else if (c == '(') {
                pushChar(&ops, c);
            }
            else if (c == ')') {
                while (!isCharEmpty(&ops) && peekChar(&ops) != '(') {
                    char op = popChar(&ops);
                    Node *r = popNode(&nodes);
                    Node *l = popNode(&nodes);
                    Node *n = newNode(op);
                    n->left = l;
                    n->right = r;
                    pushNode(&nodes, n);
                }
                popChar(&ops);
            }
            else {
                while (!isCharEmpty(&ops) && peekChar(&ops) != '('
                       && prec(peekChar(&ops)) >= prec(c)) {
                    char op = popChar(&ops);
                    Node *r = popNode(&nodes);
                    Node *l = popNode(&nodes);
                    Node *n = newNode(op);
                    n->left = l;
                    n->right = r;
                    pushNode(&nodes, n);
                }
                pushChar(&ops, c);
            }
        }
    
        while (!isCharEmpty(&ops)) {
            char op = popChar(&ops);
            Node *r = popNode(&nodes);
            Node *l = popNode(&nodes);
            Node *n = newNode(op);
            n->left = l;
            n->right = r;
            pushNode(&nodes, n);
        }
        return nodes.items[0];
    }
    
    void postOrder(Node *root) {
        if (!root) return;
        postOrder(root->left);
        postOrder(root->right);
        putchar(root->data);
    }
    
    int main() {
        char expr[MAX];
        if (!fgets(expr, MAX, stdin)) return 0;
        expr[strcspn(expr, "\n")] = '\0';
    
        Node *root = buildTree(expr);
        postOrder(root);
        putchar('\n');
        return 0;
    }