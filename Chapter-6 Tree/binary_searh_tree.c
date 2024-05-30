#include <stdio.h>
#include <stdlib.h>

struct BST{
    int data;
    struct BST *left, *right;
};
struct BST *tree;

void insert_tree(int num){
    struct BST *ptr, *parentTree, *bst_ptr;
    ptr = (struct BST *) malloc(sizeof(struct BST));

    if(ptr == NULL){
        printf("cannot insert");
    }
    else {
        ptr->data = num;
        ptr -> left =NULL;
        ptr -> right = NULL;

        if(tree == NULL){
            tree = ptr;
            tree ->left = NULL;
            tree -> right = NULL;
        }
        else{
            parentTree =NULL;
            bst_ptr = NULL;
            while(bst_ptr != NULL){
                parentTree = bst_ptr;
                if(num < bst_ptr ->data){
                    bst_ptr= bst_ptr->left;
                }else{
                    bst_ptr = bst_ptr -> right;
                }
                if( num < parentTree ->data){
                    parentTree ->left = ptr;
                }
                else{
                    parentTree -> right = ptr;
                }
            }
        }
        printf("The %d is inserted", num);

    }
}




int main(){
    int element;
    printf("Enter the Number:\n");
    scanf("%d", &element);
    insert_tree(element);
    return 0;
}
