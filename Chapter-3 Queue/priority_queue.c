// implementation of ascending priority queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

struct CQueue{
    int data[SIZE];
    int rear;
    int front;
};

typedef struct CQueue pro_queue;

void insert(pro_queue*);
void delete_queue(pro_queue*);
void display(pro_queue*);

int main(){
    int choice;
    pro_queue *queue;
    queue = (pro_queue *) malloc(sizeof(pro_queue));
    queue->rear = -1;
    queue->front = 0;
    printf("Which Operation do you want to performed.\n");
    printf("1: Enqueue \n 2: Dequeue \n3.Display \n4.Exit");
    do{
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Insert Operation.\n");
                insert(queue);
                break;
            case 2:
                printf("Delete Operation.\n");
                delete_queue(queue);
                break;
            case 3:
                printf("Display Operation:\n");
                display(queue);
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid Choice");
        }
    }
    while(choice < 5);

    return 0;
}


void insert(pro_queue *queue){
    int data;
    if(queue->rear ==SIZE-1){
        printf("Queue is Full");
    }
    else{
        printf("Enter the data to be inserted\n");
        scanf("%d",&data);
        queue->rear++;
        queue -> data[queue->rear] =data;
    }

}

void delete_queue(pro_queue *queue){
    int i, temp=0;
    int value = queue -> data[queue->front];
    if(queue->rear < queue->front){
        printf("Queue is empty\n");

    }
    else{
        for(i=queue->front+1;i< queue->rear;i++){
            if(value > queue->data[i]){
                temp =i;
                value = queue->data[i];
            }
        }

        for(i= temp;i < queue->rear-1; i++)
        {
            queue->data[i] = queue->data[i+1];

        }
        queue->rear--;
        printf("The deleted value is %d", value);
    }
}


void display(pro_queue *queue){
    int i;
    if(queue->rear <queue->front){
        printf("Queue is Empty");
        exit(1);
    }
    else{
        for(i =queue->front;i<=queue->rear;i++){
            printf("%d \n", queue->data[i]);
        }
    }
}
