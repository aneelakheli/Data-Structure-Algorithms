#include <stdio.h>

int Binary_Search(int array[100], int left, int right, int key){
    int mid;
    int flag = 0;
    if(left <=  right){
        mid = (left + right) / 2;
        if(key==array[mid]){
            printf("The %d value is found.\n", array[mid]);
            flag = mid;
        }
        else if(key < array[mid]){
            return Binary_Search(array, left, mid-1, key);
        }
        else{
            return Binary_Search(array, mid -1 , right, key);
        }
    }else{
        return flag;
    }
}


int main(){
    int num, array[100], i, key, flag;
    printf("Enter no of data item:\n");
    scanf("%d", &num);
    printf("Enter %d data item in sorted form: \n", num);
    for(i=0;i<num;i++){
        scanf("%d", &array[i]);
    }
    printf("Enter searched item:\n");
    scanf("%d", &key);
    flag = Binary_Search(array, 0, num-1, key);
    if(flag==0){
        printf("Search unsuccessful");
    }else{
        printf("Search successfully found at location %d ", flag+1);
    }
    return 0;
}
