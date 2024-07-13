#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[100];
    int size;
    int length;
};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y= temp;
}

void display_array(struct Array arr){
    int i;
    for(i=0;i<arr.length;i++){
        printf(" %d ", arr.A[i]);
    }
}

void insert_array(struct Array *arr, int x){
    int i =arr->length-1;
    if(arr->length == arr->size){
        return ;
    }
    while( i >=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int is_sorted(struct Array arr){
    int i;
    for(i=0; i < arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void re_arrange(struct Array *arr){
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j){
        while(arr->A[i] <0){ i++;}
        while(arr->A[j]>=0){ j++;}

        if(i < j){swap(&arr->A[i], &arr->A[j]);}
    }
}



int main(){
    struct Array arr= {{1,2,3,5,7,9,-1,-2}, 15, 9 };
    //printf("%d \n", is_sorted(arr));
   // insert_array(&arr, 6);
    re_arrange(&arr);
    display_array(arr);
    return 0;
}
