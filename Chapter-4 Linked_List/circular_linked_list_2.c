#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    Head = (struct Node*) malloc(sizeof(struct Node));
    Head ->data =A[0];
    Head->next = Head;
    last = Head;

    for(i=1;i<n;i++){
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = last ->next;
        last->next =t;
        last=t;
    }
}

void display(struct Node *h){
    do{
        printf("\n%d ", h->data);
        h=h->next;
    }while(h!=Head);
    printf("\n");
}


void recursive_display(struct Node *h){
    static int flag= 0;
    if(h != Head || flag==0){
        flag = 1;
        printf("%d ", h->data);
        recursive_display(h->next);
    }
    flag = 0;
}


int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}


void insert(struct Node *p ,int pos, int n){
    int i;
    struct Node *temp;
    if(pos < 0 || pos >Length(Head)){
        return 0;
    }
    if(pos == 0){
        temp = (struct Node *)malloc (sizeof(struct Node));
        temp->data =n;
        if(Head ==NULL)
        {
            Head =temp;
            Head ->next = Head;
    }
    else{
        while(p->next !=Head) p=p->next;
        p->next =temp;
        temp->next =Head;
        Head =temp;
        }
    }
    else{
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
        temp= (struct Node *) malloc(sizeof(struct Node));
        temp->data=n;
        temp->next =p->next;
        p->next =temp;
    }
}


int Delete_Data(struct Node *p, int index){
    struct Node *q;
    int i,x ;

    if(index <0 || index > Length(Head)){
        return 0;
    }
    if( index ==1){
        while(p->next !=Head) p=p->next;
        x=Head->data;
        if(Head ==p){
            free(Head);
            Head = NULL;
        }
        else{
            p->next = Head->next;
            free(Head);
            Head =p->next;
        }
    }
    else{
        for(i=0;i<index-2;i++){
            p=p->next;

        }
        q=p->next;
        p->next = q->next;
        x=q->data;
        free(q);
    }
}

int main(){
    int A[] = {2,3,4,5,6};
    create(A, 5);
    display(Head);
    recursive_display(Head);
    insert(Head,  3, 34);
    Delete_Data(Head, 2);
    display(Head);
}
