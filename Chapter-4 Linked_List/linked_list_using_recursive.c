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

int count(struct Node *p){
    int length =0;
    while(p){
        length++;
        p=p->next;
    }
    return length;
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


int sum(struct Node *p){
    int total=0;
    while(p!=NULL){
        total+=p->data;
        p=p->next;
    }
    return total;
}


//recursive count function

int R_count(struct Node *p){
    if(p!=NULL){
        return R_count(p->next) + 1;
    }else{
        return 0;
    }

}

int R_sum(struct Node *p){
    if(p==NULL){
         return 0;
    }
    return R_sum(p->next)+p->data;
}


int max_num(struct Node *p){
    int max = 0;

    while(p){
        if(p->data >max){
            max = p->data;
            p= p->next;
        }
    }
    return max;
}

int R_Max(struct Node *p){
    int max =0;

    if(p==NULL){
        return 0;
    }
    max = R_Max(p->next);
    if(max >p->data)
    return max;
    else return p->data;
}


//this is optimization using- "move to front" approach.
struct Node * l_search(struct Node *p, int key){

    struct Node *q= NULL;

    while(p !=NULL){
        if(key ==p->data){
             q->next = p->next;
             p->next = first;
             first = p;
             return p;
        }
        q=p;
        p= p->next;
    }
    return NULL;

}


struct Node * R_linear_search(struct Node *p, int key){
    if(p==NULL){
        return NULL;
    }
    else if(key == p->data){
        return p;
    }
    return R_linear_search(p->next, key);
}

void insert_at(struct  Node *p, int index, int x)
{
    struct  Node *t;
    int i;
    if(index <0  || index > count(p)){
        return ;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data =x;
    if(index ==0 ){
        t->next = first;
        first =t;
    }
    else{
        for(i=0;i<index-1;i++){
            p =p->next;
        }
        t->next= p->next;
        p->next =t;
    }

}

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
}
for(i=1;i<n;i++){
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
}


int main(){
    struct Node *temp;
    int A[] =  {2,3,4,5,6,7,8};
    create(A,7);
    printf("The total length is %d\n\n", count(first));

    insert_at(first, 3, 56);

    temp = l_search(first, 5);
    if(temp){
        printf("\n\nKey is Found %d\n\n ", temp->data);
    }else{
        printf("Key is not found\n\n\n");
    }

    temp = R_linear_search(first, 34);
    if(temp){
        printf("\n\nKey is Found %d\n\n ", temp->data);
    }else{
        printf("Key is not found\n\n\n");
    }

    display(first);
    R_Display(first);

    printf("\n\nThe total sum is %d\n",sum(first));
    printf("\n\nThe total sum is %d using recursive function\n", R_sum(first));
    printf("\n\nThe maximum number is %d\n", max_num(first));
    printf("\n\nThe maximum number is %d using recursion\n", R_Max(first));

    insert_at(first, 5, 900);
    display(first);

    return 0;
}

