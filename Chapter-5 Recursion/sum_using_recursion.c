#include <stdio.h>

int sum(int num){
    if(num ==0){
        return 0;
    }
    else{
        return sum(num-1) +num;
    }
}

int i_sum(num){
    int i, total =0;
    for(i=0;i<=num;i++){
        total +=i;
    }
    return total;
}

int formula_sum(int num){

    return (num * (num +1))/2;
}


int factorial_number(int num){
    if(num ==0){
        return 1;
    }
    else{
        return factorial_number(num-1) * num;
    }
}

int main(){
    int result, fact_result;
    // result = sum(5);
    // result = i_sum(10);
    result = formula_sum(10);
    printf("The sum is %d\n",result);
    fact_result = factorial_number(5);
    printf("The Total number of factorial number is: %d", fact_result);

    return 0;
}
