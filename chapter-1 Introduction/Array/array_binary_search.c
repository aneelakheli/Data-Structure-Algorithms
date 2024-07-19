#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[50];
    int size;
    int length;
};


void display(struct Array arr){
    int i;
    for(i=0;i<arr.length;i++){
        printf("%d ", arr.A[i]);
    }
}

int binary_search(struct Array arr, int key){
    int low, mid, high;
    low =0;
    high = arr.length-1;
    while(low <=high){
        mid = (low +high)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            high =mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int Recursive_Binary_Search(int a[], int low, int high, int key){
    int mid =0;
    if(low <=high){
        mid = (low +high)/2;
        if(key = a[mid]){
            return mid;
        }
        else if(key < a[mid]){
            return Recursive_Binary_Search(a, low, mid-1, key);
        }
    }
    else{
        return Recursive_Binary_Search(a, mid+1, high, key);

    }
    return -1;

}


struct Array* merge(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i=j=k=0;
    struct  Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j <arr2->length){
        if(arr1 ->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else{
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for(;i<arr1->length;i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(;j<arr1->length;j++){
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = arr1->length +arr2->length;
    arr3->size =10;

    return arr3;
}



int main(){
    struct Array arr = {{2,3,4,5,6,23,25,29,32,33,37,38,41,43,44,54,56},10,9};
    printf("The result is  %d \n", binary_search(arr, 43));

    struct Array arr1 = {{1,4,6,7,23}, 10,5};
    struct Array arr2 = {{2,3,5,9,11}, 10,5};
    struct Array *arrr3;

    arrr3  = merge(&arr1, &arr2);
    display(*arrr3);
    return 0;
}

