#include <stdio.h>

double e(int x, int n){
    static double p=1, f=1;
    double result;
    if(n ==0){
        return 1;
    }
    result = e(x, n-1);
    p=p*x;
    f= f*n;
    return result+p/f;

}



double horner_taylor(int n, int m){
    static double s;
    if(m==0){
        return s;
    }
    s= 1 + n * s/ m;
    return horner_taylor(n, m-1);
}


double iterative_taylor(int n, int m){
    double s = 1;
    int i;
    double num=1, deno=1;
    for(i=1;i<=m;i++){
        num*=n;
        deno*=i;
        s+=num/deno;
    }
    return s;

}

int main(){
    printf(" %lf \n", e(2,10));
    printf("The value for taylor series using hanor is %f \n", horner_taylor(2, 10));
    printf("The iterative approach for finding taylor series is %f \n", iterative_taylor(2, 10));
    return 0;
}
