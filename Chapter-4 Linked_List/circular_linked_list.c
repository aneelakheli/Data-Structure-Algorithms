
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
void insert_at_end(int);
void delete_first();
void delete_end();
void display();

int main(){
    int choice;
    int element;
     do{
        printf("\n Menu for Program:\n");
        printf("1. insert item \n2. insert at end. \n3. delete first \n4. delete last element \n5. Display items\n6. exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\n Enter item to be inserted.\n");
                scanf("%d",&element);
                insert_at_first(element);
                break;
            case 2:
                printf("Enter item to be insert at end position");
                scanf("%d",&element);
                insert_at_end(element);
                break;
            case 3:
                delete_first();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                display();
                break;
            case 6:
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

   else if(first == NULL){
         new_node ->next =new_node;
    first = new_node;
    last = new_node;
    }else{
        new_node ->next = first;
        first = new_node;
        last -> next = new_node;
    }

}

void insert_at_end(int item) {
    NodeType *new_node;
    new_node = (NodeType *)malloc(sizeof(NodeType));
    new_node->data = item;
    if(first = NULL){
        first = new_node;
        last = new_node;
        new_node->next = new_node;
    }
    else{
        last -> next =new_node;
        last = new_node;
        new_node->next=first;
    }

}


void delete_first(){
    NodeType *temp;
    temp = first;
    if(first ==NULL){
        printf("Cannot Deletion");
        return ;
        }
        else if(first == last){
        first = NULL;
        last =NULL;
        free(temp);
        }
        else{
            first = first ->next;
            last ->next = first;
            free(temp);
        }
}


void delete_end(){
    NodeType  *temp;
    temp= last;
    if(first == NULL){
        printf("cannot performed Deletion");
        return;
    }
    else if(first -> next ==NULL){
        first =NULL;
        last = NULL;
        free(temp);
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = first;
        last = temp;
        temp = first;
        free(temp);

    }
}


void display(){
    NodeType *temp;
    printf("\nThe Nodes are:\n");
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
