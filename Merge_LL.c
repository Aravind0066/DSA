#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* newnode(int val){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    return n;
}

void append(struct node** head, int val){
    struct node* n = newnode(val);
    if(*head == NULL){
        *head = n;
        return;
    }
    struct node* temp = *head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = n;
}

void printlist(struct node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void split(struct node* head, struct node** a, struct node** b){
    struct node* slow = head;
    struct node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

struct node* merge(struct node* a, struct node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    struct node* result = NULL;
    if(a->data <= b->data){
        result = a;
        result->next = merge(a->next, b);
    }else{
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void mergeSort(struct node** head){
    struct node* a = NULL;
    struct node* b = NULL;
    split(*head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);
    *head = merge(a,b);
}

int main(){
    int n, x;
    scanf("%d",&n);
    struct node* head = NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        append(&head,x);
    }
    mergesort(&head);
    printlist(head);
    return 0;
}
