#include <stdio.h>
//#include <conio.h>

#define SIZE 10

typedef struct Queue{
int rear, front;
int queue[SIZE];
} qe;

//Queue qe;

void insertItem(qe *);   //function prototype
void deleteItem(qe *);  //function prototype
void displayItem(qe *); //function prototype

int main(){
int choose;
qe *q = (qe *) malloc(sizeof(qe));
if(q ==NULL){
    printf("Memory allocation failed\n");
    exit(1);
}
q->rear=-1;
q->front=0;
printf("\n Menu for programs:\n\n");
printf("\n\n 1. insert, 2. delete, 3. Display\n\n");
do{
    printf("\n Enter the Choice\n");
    scanf("%d", &choose);
    switch(choose){
        case 1:
            insertItem(q); //calling the function
            break;
        case 2:
            deleteItem(q);
            break;
        case 3:
            displayItem(q);
            break;
        default:
            printf("Your choice is Invalid\n");

    }
}
while(choose < 10);
return 0;
}


void insertItem(qe *q){
int ele;
printf("Enter the data to be inserted\n\n");
scanf("%d", &ele);
if(q->rear == SIZE-1){
printf("Queue is Full\n");
}
else{
q->rear++;
q->queue[q->rear] = ele;
}

}


void deleteItem(qe *q){
int ele;
if(q->rear < q->front){
printf("Queue is Empty");
}
else{
printf("Delete item is\n");
ele = q->queue[q->front];
 q->front++;
printf("deleted item is %d", ele);

}
}


void displayItem(qe *q){
int i;
if(q->rear < q->front){
printf("Queue is Empty");
}
else{
    for(i=q->front;i< q->rear; i++){
    printf("\n %d \n",q->queue[i]);
    }
}
}




