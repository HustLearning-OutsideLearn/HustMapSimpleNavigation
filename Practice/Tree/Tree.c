#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node* InitTree(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* InsertLeft(struct node * root, int value){
    root->left = InitTree(value);
    return root->left;
}

struct node* InsertRight(struct node * root, int value){
    root->right = InitTree(value);
    return root->right;
}

void InorderTraversal(struct node * root){
    if(root == NULL) return;
    InorderTraversal(root->left);
    printf("%d -> ", root->data);
    InorderTraversal(root->right);
}

void PreorderTraversal(struct node * root){
    if(root == NULL) return;
    printf("%d -> ", root->data);
    InorderTraversal(root->left);
    InorderTraversal(root->right);
}

void PostorderTraversal(struct node * root){
    if(root == NULL) return;
    InorderTraversal(root->left);
    InorderTraversal(root->right);
    printf("%d -> ", root->data);
}

void main(){
    struct node * TreeRoot = InitTree(10);
    InsertLeft(TreeRoot, 12);
    InsertRight(TreeRoot, 9);
    InsertLeft(TreeRoot->left, 5);
    InsertRight(TreeRoot->left, 6);

    printf("Inorder traversal \n");
    InorderTraversal(TreeRoot);

    printf("\nPreorder traversal \n");
    PreorderTraversal(TreeRoot);

    printf("\nPostorder traversal \n");
    PostorderTraversal(TreeRoot);
}