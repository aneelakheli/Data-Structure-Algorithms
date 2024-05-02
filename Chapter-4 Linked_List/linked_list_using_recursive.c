#include <stdio.h>
#include <stdlib.h>



struct Node{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n){
    int i;
    struct Node *p=NULL, *last = NULL;
    first = (struct Node *) malloc(sizeof(struct Node));
    first ->data = A[0];
    first -> next= NULL;
    last = first;

    for(i=1; i<n; i++){
        p = (struct Node *) malloc(sizeof(struct Node));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;

    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d \t", p->data);
        p=p->next;
    }
    printf("\n\n\n");
}


void R_Display(struct Node *p){
    if(p!=NULL){
    // First calling the function after returing it will print the value. so in this case
    // the values are printing in reserver order.
        R_Display(p->next);
        printf("%d \t", p->data);
    }

}


int main(){

    int A[] =  {2,3,4,5,6,7,8};
    create(A,6);
    display(first);
    R_Display(first);
    return 0;
}