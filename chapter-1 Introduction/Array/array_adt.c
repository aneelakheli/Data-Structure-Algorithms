#include <stdio.h>
#include <stdlib.h>


struct Array{
    int *A;
    int size;
    int length;
};

void display_array(struct Array arr){
    int i;
    printf("\n Elements are :\n");
    for(i=0;i<arr.length;i++)
        printf("%d", arr.A[i]);
}


int main(){
    struct Array arr;
    int n, i;
    printf("Enter size of array:\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));

    if(arr.A ==NULL){
        printf("Memory allocation failed \n");
        return 1;
    }
    arr.length = 0;

    printf("Enter the number of numbers: \n");
    scanf("%d", &n);

    printf("Enter all Elements\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    display_array(arr);

    return 0;
}
