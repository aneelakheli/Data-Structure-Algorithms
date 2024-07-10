#include <stdio.h>

struct Array {
    int A[50];
    int size;
    int length;
};

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


int main(){
    struct Array arr = {{2,3,4,5,6,23,25,29,32,33,37,38,41,43,44,54,56},10,9};
    printf("The result is  %d \n", binary_search(arr, 43));
    return 0;
}

