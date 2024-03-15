#include <stdio.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int top;
} stack;

void createEmpty(stack *s);
void push(stack *s, int);
void pop(stack *s);
void display(stack *s);

int main(){
    int ele, choice;
    stack *s;
    int flag= 1;
    createEmpty(s);
    do{
        printf("\n\n Enter your choice");
        printf("\n\n 1: push the elements");
        printf("\n\n 2: To display the elements");
        printf("\n\n 3: Pop the elements");
        printf("\n\n 4: Exit");
        printf("\n\n Enter of your choice: \t");

        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\n Enter the number:");
                scanf("%d",&ele);
                push(s, ele);
                break;
            case 2:
                display(s);
                break;
            case 3:
                pop(s);
                break;
            case 4:
                flag =0;
                break;
            default:
                printf("\n Invalid Choice.");
        }
    }
    while(flag);
    return 0;
}

void createEmpty(stack *s){
    s->top=-1;
}

int isEmpty(stack *s){
    if(s->top<0){
    return 1;}
    else return 0;
}

int isFull(stack *s){
    if(s->top==MAX-1) return 1;
    else return 0;
}

void push(stack *s, int ele){
    if(isFull(s)) {
        printf("\n\n The stack is overflow:");
        }
        else{

        s->items[++(s->top)] = ele;
        }
}

void display(stack *s){
    int i;
    if(isEmpty(s))
    {
    printf("The stack does not contact any elements.\n");
    }
    else{
        printf("\nThe Element in the stack are\n");
        for(i=s->top;i>=0;i--){
        printf("%d\n",s->items[i]);
        }
    }
}

void pop(stack *s){
    if(isEmpty(s)){
    printf("\n Stack underflow:\n");
    }
    else{
        printf("\n\n The deleted is %d", s->items[s->top--]);
    }
}

