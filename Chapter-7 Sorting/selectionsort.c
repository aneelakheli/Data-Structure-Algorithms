#include <stdio.h>

void selection_sort(int arr[], int number){
    int i, index, j, temp, min;
    for(i=0;i<number;i++){
        min =arr[i];
        index =i;
        for(j=i+1;j<number;j++){
            if(arr[j] < min){
                min = arr[j];
                index =j;
            }
        }
        if(i!=index){
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

int main(){
    int n=8;
    int a[8], i;
    printf("Enter data items\n");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("The data item before sorting:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    selection_sort(a,n);
    printf("\n");
    printf("The data item after sorting\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}
