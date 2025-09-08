#include <stdio.h>

typedef struct{
    int arr[1000];
    int top;
}Stack;

void push(Stack* a, int val){
    a->arr[++a->top] = val;
}

int pop(Stack* a){
    return a->arr[(a->top)--];
}

void hanoi(Stack* A, char a, Stack* B, char b, Stack* C, char c, int n){
    if(n==1){ 
        //3push(B, pop(A)); 
        int disk = pop(A); 
        push(B, disk);
        printf("Move %d from %c to %c\n", disk, a, b); 
        return;
    }
    else {
        hanoi(A, a, C, c, B, b, n-1);
        //push(B, pop(A));
        int disk = pop(A);
        push(B, disk);
        printf("Move %d from %c to %c\n", disk, a, b);

        hanoi(C, c, B, b, A, a, n-1);
    }
}

int main(){
    int n;
    scanf("%d",&n);

    Stack a,b,c;
    a.top = b.top = c.top = -1;

    for(int i=n; i>0; i--){
        push(&a, i);
    }

    hanoi(&a, 'A', &b, 'B', &c, 'C', n);

    return 0;
}