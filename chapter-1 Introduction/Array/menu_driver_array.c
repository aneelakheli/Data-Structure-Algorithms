#include <stdio.h>
#include <stdlib.h>


struct Array{
    int A[100];
    int size;
    int length;
};


void insert_array(struct Array *arr,int index,int x){
    int i;
    if(index>=0 && index <=arr->length){
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
            arr->A[index]=x;
            arr->length++;
    }
}


void insert_sort(struct Array *arr, int x){
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

void Display(struct Array arr){
    int i;
    printf("\n Element are \n");
    for(i=0;i<arr.length;i++){
        printf("%d ", arr.A[i]);
    }
}

int main(){

    struct Array arr1;
    int ch, index, x;

    printf("Enter size of Array:\n");
    scanf("%d", &arr1.size);
    arr1.length=0;

    printf("Menu \n");
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("3. Search \n");
    printf("4. Sum \n");
    printf("5. Display \n");
    printf("6. Exit \n");

    printf("Enter your choice: \n");
    scanf("%d", &ch);


    do{
        switch(ch)
        {
            case 1:printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                insert_array(&arr1,index,x);
                break;
            case 5:
                Display(arr1);
                break;
            default :
                printf("Error value");
        }
    }while(ch<6);
    return 0;
}
