#include <stdio.h>

double fact(int n){
    if( n==0){
        return 1;
    }
    else{
        return fact(n-1) *n;
    }
}


double nCr(int n, int r){
    int num, deno;
    num = fact(n);
    deno = fact(r) *fact(n-r);


    return num/deno;
}


double NCR(int n, int r){
    if(n==r ||r==0){
        return 1;
    }
    return NCR(n-1, r-1)+ NCR(n-1, r);
}


int main(){
    printf("the value is %f",nCr(4,2));
    return 0;
}
