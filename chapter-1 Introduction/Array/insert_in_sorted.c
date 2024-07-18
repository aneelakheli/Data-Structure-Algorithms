#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[100];
    int size;
    int length;
};


void swap(int *x, int *y){
     int temp = *x;
     *x = *y;
     *y =temp;
}


void display(struct Array arr){
    int i;
    for(i=0;i <arr.length;i++){
        printf("%d  ", arr.A[i]);

    }
}

int is_sorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
        return 1;
    }
}


void insert_sorted(struct Array *arr, int x){
    int i= arr->length-1;
    if(arr -> length ==arr ->size){
        return;
    }
    while( i >=0 && arr ->A[i] > x){
        arr ->A[i+1] = arr -> A[i];
        i--;
    }
    arr -> A[i+1] =x;
    arr -> length++;
}

void re_arrange(struct Array *arr){
    int i,j;
    i =0;
    j = arr -> length-1;

    while(i < j){
        while(arr ->A[i] <0) i++;
        while (arr->A[i] >=0) j--;
        if(i <j) swap(&arr->A[i], &arr->A[j]);
    }
}


int main(){

    struct Array arr = {{13,6 ,1,2,4,5, 9}, 10, 5};

    // insert_sorted(&arr, 15);
    // insert_sorted(&arr , 6);
    // insert_sorted(&arr, 12);

    re_arrange(&arr);
    printf( "The array is sorted %d \n",is_sorted(arr));
    display(arr);

    return 0;
}
