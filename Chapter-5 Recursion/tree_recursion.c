#include <stdio.h>

void tree_recursion(num){
    if(num >= 1){
        printf("%d \t", num);
        tree_recursion(num-1);
        tree_recursion(num-1);
    }
}

int main(){
    int num, tree_result;
    printf("Enter the number:\n");
    scanf("%d", &num);
    tree_recursion(num);
    return 0;
}
