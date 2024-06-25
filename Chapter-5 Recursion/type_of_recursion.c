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

// indirect function

void recursion_first_A(int num){
    if(num > 0){
        printf("First Recursion: %d\n", num);
        recursion_second_B(num-1);
    }
}

void recursion_second_B(int num){
    if(num >1){
        printf("Second Recursion: %d\n", num);
        recursion_first_A(num/2);
    }
}


//nested recursion function

int nested_recursion(int num){
    if (num < 100){
        return num +1000;
    }
       return nested_recursion(nested_recursion(num-11));
}

int main(){
    int tail_result, head_result, num, result;
    printf("Enter the Number: \n");
    scanf("%d", &num);
    //tail_result = tail_recursion(num);
    //head_result = head_recursion(num);
    //recursion_first_A(40);
    result = nested_recursion(num);
    printf("\n\nThe result is %d\n\n", result);
    return 0;
}
