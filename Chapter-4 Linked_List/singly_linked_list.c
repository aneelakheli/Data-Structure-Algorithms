#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct node *next;
};

typedef struct Node NodeType;
NodeType *first =NULL;
NodeType *last = NULL;

void insert_at_first(int);
void insert_at_given_position(int);
void insert_at_end(int);
void delete_first();
void delete_end();
void delete_nth_node();
void info_sum();
void count_nodes();
void display();

int main(){
    int choice;
    int element;
     do{
        printf("\n Menu for Program:\n");
        printf("1. insert item \n2. insert at given position \n3. insert at end. \n4. delete first \n5. delete last element \n6. delete nth element \n7. info sum\n8. count nodes\n9. Display items\n10. exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\n Enter item to be inserted.\n");
                scanf("%d",&element);
                insert_at_first(element);
                break;
            case 2:
                printf("\n Enter item to be insert at desired position");
                scanf("%d",&element);
                insert_at_given_position(element);
                break;
            case 3:
                printf("Enter item to be insert at end position");
                scanf("%d",&element);
                insert_at_end(element);
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_nth_node();
                break;
            case 7:
                info_sum();
                break;
            case 8:
                count_nodes();
                break;
            case 9:
                display();
                break;

            case 10:
                exit(1);
                break;
            default:
                printf("invalid Choice \n ");
        }
    }
    while(choice < 10);
    return 0;
}

void insert_at_first(int item){
    NodeType *new_node;
    new_node = (NodeType *) malloc(sizeof(NodeType));
    if(new_node == NULL){
        printf("Memory allocation Failed");
        return;
    }
    new_node ->next =first;
    new_node ->data = item;

    if(first == NULL){
        last = new_node;
    }
        first= new_node;
}

void insert_at_given_position(int item){
    int pos, i;
    NodeType *new_node;
    NodeType *temp;
    temp -= first;
    new_node = (NodeType *) malloc (sizeof(NodeType));
    new_node -> data = item;
    if(first == NULL){
        new_node ->next =NULL;
        first = new_node;
    }
    else{
        printf("Enter position of a node at which you want to insert an new node \n");
        scanf("%d",&pos);
        for(i=1;i<pos-1;i++){
            temp = temp->next;
        }
        new_node -> next = temp -> next;
        temp -> next =new_node;

    }

}

void insert_at_end(int item) {
    NodeType *new_node;
    NodeType *temp;
    temp = first;
    new_node = (NodeType *)malloc(sizeof(NodeType));
    new_node->data = item;
    if(temp = NULL){
        new_node->next = NULL;
        first = new_node;
    }
    else{
        while(temp->next!=NULL){
            temp= temp->next;
        }
        new_node->next=NULL;
        temp->next=new_node;
    }

}


void delete_first(){
    NodeType *temp;
    if(first ==NULL){
        printf("Cannot Deletion");
        return ;
        }
        else{
        temp = first;
        first = first->next;
        free(temp);
        }
}


void delete_end(){
    NodeType *hold , *temp;
    if(first == NULL){
        printf("cannot performed Deletion");
        return;
    }
    else if(first -> next ==NULL){
        hold=first;
        first =NULL;
        free(hold);
    }
    else{
        temp = first;
        while(temp->next != NULL){
            temp = temp->next;
        }
        hold =temp->next;
        temp->next=NULL;
        free(hold);

    }
}


void delete_nth_node(){
    NodeType *hold, *temp;
    int pos , i;
    if(first ==NULL){
        printf("Void Deletion");
        return ;
    }
    else{
        temp = first;
        printf("enter the position to perform deletion");
        scanf("%d", &pos);
        for(i=1;i<pos-1;i++){
            temp = temp->next;
        }
        hold =temp->next;
        temp->next = hold ->next;
        free(hold);
    }
}

void display(){
    NodeType *temp;
    temp =first;
    printf("\nThe Nodes are:\n");
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void count_nodes(){
    int count =0;
    NodeType *temp;
    temp =first;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("Total Counts are: %d\n", count);
}


void info_sum(){
    NodeType *temp;
    temp = first;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp= temp->next;
    }
}
