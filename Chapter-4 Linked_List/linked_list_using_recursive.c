#include <stdio.h>
#include <stdlib.h>



struct Node{
    int data;
    struct Node *next;
} *first = NULL, *second =NULL, *third =NULL;

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

void create_another(int A[], int n){
    int i;
    struct Node *p=NULL, *last = NULL;
    second = (struct Node *) malloc(sizeof(struct Node));
    second ->data = A[0];
    second -> next= NULL;
    last = second;

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

int remove_duplicate(struct Node *p){
    struct Node *q= p->next;
    while(q!=NULL){
        if(p->data !=q->data){
            p =q;
            q=q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q= p->next;
        }
    }
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

void create_list(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
for(i=1;i<n;i++){
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
}
}
void sorted_insert(struct Node *p, int x){
    struct Node *t , *q = NULL;
    t = (struct Node *) malloc(sizeof(struct Node));
    t ->data =x;
    t ->next =NULL;

    if(first == NULL){
        first = t;
    }
    else{
        while(p && p ->data< x){
            q = p;
            p=p->next;
        }
        if(p ==first)
        {
            t->next = first;
            first = t;
        }
        else{
            t->next= q->next;
            q->next = t;
        }
    }
}


int delete_value(struct Node *p, int index){
    struct Node *q=NULL;
    int x = -1,i ;
    if(index < 1 || index >count(p)){
        return -1;
    }
    if(index == 1){
        q = first;
        x = first ->data;
        first= first ->next;
        free(q);
        return x;
    }
    else{
        for(i=0; i<index; i++){
            q=p;
            p = p->next;
        }
        q->next =p->next;
        x = p->data;
        free(p);
        return x;
    }

}


int isSorted(struct Node *p){
    int x = -6655;
    while(p != NULL){
        if(p->data < x){
            return 0;
        }
        x= p->data;
        p= p->next;
    }
    return 1;


}

void reverse_element(struct Node *p){
    int *A, i=0;
    struct Node *q;
    A= (int *) malloc(sizeof(int) *count(p));

    while(q!=NULL){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q= p;
    i--;
    while(q!=NULL){
            q->data =A[i];
            q= q->next;
            i--;
    }

}

void reverse_address(struct Node *p){
    struct Node *q= NULL , *r=NULL;
    while(p!=NULL){
        r= q;
        q=p;
        p=p->next;
        q->next =r;
    }
    first=q;
}


void recursive_reverse(struct Node *q, struct Node *p){
    if(p){
        recursive_reverse(p, p->next);
        p->next= q;
    }
    else{
        first =q;
    }
}

void concat(struct Node *p, struct Node *q){
    third =p;

    while(p->next!=NULL){
        p =p->next;
    }
    p->next=q;
}


void merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data  < q->data){
        third = last =p;
        p=p->next;
        third->next =NULL;
    }else{
        third = last = q;
        q= q->next;
        third->next = NULL;
    }

    while(p && q){
        if(p->data < q->data){
            last->next= p;
            last = p;
            p=p->next;
            last ->next= NULL;
        }
        else{
            last->next = q;
            last =q;
            q=q->next;
            last ->next =NULL;
        }

    }
    if(p) last ->next =p;
    if(q) last ->next =q;
}

int is_Loop(struct Node *f){
    struct Node *p, *q;
    p=q=f;


    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }
    while(p && q  &&p!= q);
    if(p==q){
        return 1;
    }else{
        return 0;
    }
}



int main(){
    struct Node *temp;

    struct Node *t1, *t2;
    int C[] = {10,20,30,40,50};
    create(C, 5);
    t1 =first->next ->next;
    t2 = first->next->next->next->next;
    t2->next= t1;

    printf("%d\n", is_Loop(first));


    int A[] =  {12,13,24,25,26,27,38};
    int B[] = {10,14,36,37,48};
    create(A, 5);
    create_another(B, 5);


   // merge(first, second);

    display(third);
    printf("before mergering");

    printf("first\n");
    display(first);
    printf("\n\n");


    printf("Second \n");
    display(second);
    printf("\n\n");

    concat(first, second);

    printf("Concatinated \n");
    display(third);
    printf("\n\n");



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
    delete_value(first, 3);
    display(first);

    return 0;
}

