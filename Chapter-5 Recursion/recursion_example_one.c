#include <stdio.h>

//printing the value before returning the function.
int recursive_one(int num){
    if(num < 1){
        return 1;
    }
    else{

        printf("\n recursive in descending order%d", num);
        recursive_one(num-1);
    }
}

//returning the function before printing the value.
int recursive_before_calling(int num){
    if(num <1){
        return 1;
    }
    else{
        recursive_before_calling(num-1);
        printf("\n recursive in ascending order %d", num);
    }
}


int main(){
    int num;
    printf("Enter the Number:\n");
    scanf("%d", &num);
    // recursive_one(num);
    recursive_before_calling(num);
}
