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


int main(){
        int disk, source, aux, dest;
        toh(3, 1, 2, 5);
        return 0;
}
