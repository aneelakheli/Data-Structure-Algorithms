#include <stdio.h>

int fibonacci(int n){
    int t0=0, t1= 1,sum=0, i;
    if(n<=1) return n;
    for(i=2;i<=n;i++){
        sum = t0 +t1;
        t0=t1;
        t1= sum;
    }
    return sum;
}


int recursive_fib(int n){
    if(n<=1){
        return n;
    }
    else{
       return recursive_fib(n-1) +recursive_fib(n-2);
    }
}

int F[10];

int mfib(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2]= mfib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1]=mfib(n-1);
        }
        return F[n-2] +F[n-1];
    }
}



int main(){
    int i;
    for(i=0;i<10;i++){
        F[i] =-1;
    }

    printf("The value of  fibonacci series %d \n", fibonacci(10));
    printf("The value of recursive series %d \n", recursive_fib(10));
    return 0;
}
