#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};


int max_num(struct Array arr){
        int max = arr.A[0];
        int i;
        for(i=1;i<arr.length; i++)
        {
            if(arr.A[i] >max){
                max = arr.A[i];
            }
        }
        return max;
}


int get_data(struct Array arr, int index){
    if( index >=0  && index< arr.length){
        return arr.A[index];
    }
    return -1;
}

void set_data(struct Array *arr, int index, int x){
    if(index >=0 && index<arr->length){
        arr->A[index] = x;
    }
}


int min_num(struct Array arr){
        int min = arr.A[0];
        int i;
        for(i=1;i<arr.length; i++)
        {
            if(arr.A[i]<min){
                min = arr.A[i];
            }
        }
        return min;
}

int main(){
    struct Array arr = {{2,3,5,6,7,4,34,23,76,45},10,5};
        printf("Maximum element: %d\n", max_num(arr));
    printf("Minimum element: %d\n", min_num(arr));
    printf("Element at index 3: %d\n", get_data(arr, 3));

    set_data(&arr, 3, 50);
    printf("Element at index 3 after setting to 50: %d\n", get_data(arr, 3));
    return 0;
}
