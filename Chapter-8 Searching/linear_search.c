#include <stdio.h>

int main(){
    int a[100], key, i, n;
    printf("Enter the number of elements in array\n");
    scanf("%d", &n);
    printf("Enter %d numbers to search\n");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the Number to search\n");
    scanf("%d", &key);
    for(i=0;i<n;i++){
        if(a[i] == key){
            printf("%d is found in %d location", key, i+1);
            break;
        }
    }
    if(i==n){
        printf("%d is not found", key);
    }
    return 0;
}
