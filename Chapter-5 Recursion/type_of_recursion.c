#include <stdio.h>

int tail_recursion(num){
    if(num==1){
        return ;
    }
    else{
        printf("The value of tail recursion is %d\n", num);
       return tail_recursion(num-1);
    }
}


int  head_recursion(num){
    if(num == 1){
        return;
    }
    else{
        head_recursion(num-1);
        printf("The value of head recursion %d\n", num);
    }
}

int main(){
    int tail_result, head_result, num;
    printf("Enter the Number: \n");
    scanf("%d", &num);
    tail_result = tail_recursion(num);
    head_result = head_recursion(num);
    return 0;
}
