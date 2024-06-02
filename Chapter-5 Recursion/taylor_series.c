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

int main(){
    printf(" %lf \n", e(2,10));
    return 0;
}
