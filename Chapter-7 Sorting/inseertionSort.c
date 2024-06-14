#include <stdio.h>

void insertion_sort(int arr[], int n){
    int i, j, temp;
    for(i=0;i<n;i++){
        temp= arr[i];
        j=i-1;
        while(temp < arr[j] && j>=0){
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


int main(){
    int n =5;
    int i, array[5];
    printf("Enter the Number:\n");
    for(i=0;i<n;i++){
        scanf("%d", &array[i]);
    }

    printf("The value is before sorting" );
    for(i=0;i<n;i++){
        printf("%d \t",array[i]);
    }

    insertion_sort(array, n);
    printf("\nThe value after sorting\n");
    for(i=0;i<n;i++){
        printf("%d \t", array[i]);
    }

    return 0;
}
