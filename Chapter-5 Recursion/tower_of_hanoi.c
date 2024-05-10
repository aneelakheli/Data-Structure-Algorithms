#include <stdio.h>
#include <stdlib.h>


void toh(int disk, int source, int aux, int dest){
    if(disk == 1){
        printf("%d to %d \n", source, dest);
    }
    else if(disk >1){
        toh(disk-1,  source,  dest,  aux);
        printf("disk %d is move from %d to %d\n",disk, source, aux);
        toh( disk-1,  aux,  source,  dest);
    }

}
//  indirect recursive function .
void towerofHanoi(int disk, int source, int aux, int dest){
    if(disk == 1){
        printf("inside indirect recursive function %d to %d\n", source, dest);
    }
    else if(disk > 1){
        toh(disk-1, source, dest,  aux);
        printf(" inside indirect recursive %d to %d \n", source, aux);
        toh(disk-1, aux, source, dest);
    }

}


//tail recursion.
void fib_n(int num){
    if( num == 1){
        return 1;
    }
    else{
        printf("\n\n%d\n", num);
        return fib_n(num-1);
    }
}

int main(){
        int disk, source, aux, dest;
        toh(3, 1, 2, 5);
        towerofHanoi(5,4,6,7);
        fib_n(9);
        return 0;
}
