//a c program to perform fibbonacci series.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, result;
    printf("Enter the Number:");
    scanf("%d", &n);
    printf("Fibbonacci numbers up to %d terms:\n", n);
    result = fibbonacci_series(n);
    printf("%d \n", result);
    return 0;
}

int fibbonacci_series(int num){
    if(num ==1 || num == 2){
        return 1;
    }
    else{
        return fibbonacci_series(num-1) + fibbonacci_series(num-2);
    }

}
