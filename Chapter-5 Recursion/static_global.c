#include <stdio.h>

int func(int num){
    if(num>0){
        return func(num-1)+num;
    }
    return 0;
}

int static_fun(int num){
    static int x =0;
    if(num > 0){
        x++;
        return static_fun(num-1) +x;
    }
    return 0;
}

int main(){
    int result, static_result;
    result = func(9);
    printf("The result is: %d\n", result);
    static_result = static_fun(9);
    printf("The static result is: %d", static_result);
    return 0;

}
