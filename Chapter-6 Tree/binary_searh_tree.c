#include <stdio.h>
#include <stdlib.h>

struct BST{
    int data;
    struct BST *left, *right;
};
struct BST *tree;

typedef struct BST BinaryTree;

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


void preOrderTraversal(BinaryTree *head){
    if(head!= NULL){
        printf("The preorder Traversal is %d \n",head->info);
        preOrderTraversal(head->left);
        preOrderTraversal(head->right);
    }

}


void inOrderTraversal(BinaryTree *head){
    if(head){
        inOrderTraversal(head->left);
        printf("The Inorder Traversal %d", head->data);
        inOrderTraversal(head->right);
    }
}

void postOrderTravesal(BinaryTree *head){
    if(head !=NULL){
        postOrderTravesal(head->left);
        postOrderTravesal(head->right);
        printf("The Post Order Traversal %d", head->data);
    }

}


int main(){
    int element;
    printf("Enter the Number:\n");
    scanf("%d", &element);
    insert_tree(element);
    return 0;
}
