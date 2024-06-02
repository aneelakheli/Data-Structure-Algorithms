#include <stdio.h>


int power(int m, int n){
    if(n ==0){
        return 1;
    }
    return power(m, n-1) *m;
}

int reduce_power(int m, int n){
    if(n==0){
        return 1;
    }
    if(n%2 ==0){
        return reduce_power(m*m, n/2);
    }
    else{
        return m *reduce_power(m*m, (n-1 )/2);
    }
}

int main(){
    int result;
    result = power(2,4);
    printf("The Power value is: %d \n", result);
    result = reduce_power(2, 5);
    printf("The reduce multiplication of power function is %d\n", result);
    return 0;
}
