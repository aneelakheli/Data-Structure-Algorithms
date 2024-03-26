/*array implementation of stack */
#include <stdio.h>
#include <conio.h>
#define MAX 10
 struct stack{
        int item[MAX];
        int top;
};
typedef struct stack st;
void createEmptyStack(st *s);
void push(st *s, int);
void pop(st *s);
void display(st *s);

int main(){
int ele, choice;
st *s;
int flag=1;
clrscr();
createEmptyStack(s);
do{
                    printf("\n Enter your choice ");
printf("\n 1 : Push the Elements: ");
printf("\n 2 : To display the element ");
printf("\n 3 : pop the Element ");
printf("\n 4 : Exit");
printf("\n Enter your choice: \t ");
scanf("%d",&choice);
switch(choice){
               case 1:
                      printf("\n Enter the number ");
                      scanf("%d",&ele);
                      push(s, ele);
                      break;
               case 2:
                      display(s);
                      break;
               case 3:
                      clrscr();
                      pop(s);
                      break;
               case 4:
                      flag= 0;
                      break;
               default:
                       printf("\n Invalid choice");
               }
               }while(flag);
               getch();
               return 0;
}
/* function to create an empty stack */
void createEmptyStack(st *s){
     s-> top=-1;
     }
/*function to check whether the stack is empty or not */
int isEmpty(st *s){
    if(s->top ==-1){
              return 1;
              }
              else {
                   return 0;
                   }
    }
int isFull(st *s){
    if(s->top==MAX-1){
           return 1;                  
    }
    else{
         return 0;
         }
}

void push(st *s, int ele){
     if(isFull(s)){
           printf("\n The stack is overflow");
     }
     else{
          s->item[++(s->top)] =ele;
          }
}


void display(st *s){
     int i;
     if(isEmpty(s)){
                    printf("The stack is underflow");
                    
     }
     else{
          printf("The element in the stack is :\n");
                      for(i=s->top;i>=0;i++){
                                             printf("\n%d\n",s->item[i]);
                                             }                                             
                   }     
}

void pop(st *s)
{

if(isempty(s))
printf("\n\nstack Underflow: Empty Stack!!!");
else
printf("\n\nthe deleted item is %d:\t",s->item[s->top--]);

}

               
                         
