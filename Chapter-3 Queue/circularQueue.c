#include <stdio.h>
#include <conio.h>

#define SIZE 10

struct CircularQueue{
    int item[SIZE];
    int rear;
    int front;
}

typedef struct CircularQueue cQueue;

//function prototype.
void insertQueue(cQueue*); //for insertion the element. in the function we have one parameter
void deleteQueue(cQueue*); // for deletion the element.
void displayQueue(cQueue *); // for traversing the element.

int main()
{
    int choose;
    cQueue *temp;
    q->rear = SIZE-1;
    q->front = SIZE-1;
    clrscr();
    printf("Enter the Number for the Operation:\n");
    printf("1: Enqueue \n 2: Dequeue \n 3:Display ");
    do{
        printf("Enter Your choice");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                insertQueue(q);
                break;
            case 2:
                deleteQueue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            default:
                printf("Invalid Choice");
                break;
        }
    }while(choose<100);
    getch();
return 0;
}

void insertQueue(cQueue *q){
     int ele;
     if((q -> rear +1) % SIZE == q -> front) {
        printf("Queue is Full");
     }               //REAR =  9; 0 ==
     else{
     q-> rear = (q->rear +1) % SIZE;          // 9+1 %10 ==0, rear =0
     prinf("Enter the Element to insert");
     scanf("%d", &ele); //6
     q->item[rear] = ele; // item[0] = 6
     }

}


void deleteQueue(cQueue *q){
    if(q->rear == q->front){
        printf("Queue is Empty");
    }
    else{
    q->front = (q->front+1 )%SIZE;
    printf("Queue is Empty");
    printf("%d is deleted\n", q->item[q->front]);
    }
}


void displayQueue(cQueue *q){
    int i;
    if(q->rear ==q->front ){
        printf("Queue is Empty");
    }
    else{
        printf("item of Queue are\n");
        for(i=(q->front+1) %SIZE ; i != q->rear ; i=(i+1) %){
            printf("%d \t" , q->item[i]);
        }
        printf("%d \t", q->item[q->rear]);
    }
}


