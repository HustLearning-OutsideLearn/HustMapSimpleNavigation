#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node * rnext, * lnext;
};

typedef struct Node * PNode;

typedef struct {
    PNode H;
    PNode T;
} DoubleLinkedList;

void init(DoubleLinkedList base){
    base.H = NULL;
    base.T = NULL;
}

void isempty(DoubleLinkedList base){
    if(base.H != NULL && base.T != NULL){
        printf("NOT NULL\n");
    }else if(base.H == NULL && base.T != NULL){
        printf("LOST HEAD");
    }else if(base.T == NULL && base.H != NULL){
        printf("LOST TAIL");
    }else{
        printf("NULL");
    }
}

DoubleLinkedList * del(DoubleLinkedList base, struct Node * Q){
    PNode before, after;
    before = Q->lnext;
    after = Q->rnext;
    before->rnext = after;
    after->lnext = before;
}

PNode * find(DoubleLinkedList base, int info){
    PNode temp = base.H;
    while(temp->info != info){
        temp = temp->rnext;
    }
    return temp;
}

void main(){
    DoubleLinkedList Main_lst;
    init(Main_lst);
    isempty(Main_lst);
}