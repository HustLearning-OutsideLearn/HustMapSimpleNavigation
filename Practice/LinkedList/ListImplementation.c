#include <stdio.h>

typedef struct List
{
    int value[100];
    int size;
}List;

void init(List *L){
    L->size = 0;
}

void insert(List *L, int pos, int value){
    L->value[pos] = value;
    if(pos > L->size){
        L->size=pos+1;
    }
}

void append(List *L, int value){
    if(L->size == 99){
        printf("Dung co nhap nua");
    }else{
        L->value[L->size] = value;
        L->size++;
    }
}

void delete_the_last(List *L){
    if(L->size > 0){
        L->size--;
    }
}

void main(){
    List empty;
    init(&empty);
    append(&empty, 10);
    printf("Before removing: %d", empty.value[empty.size-1]);
    delete_the_last(&empty);
    printf("After removing: %d", empty.value[empty.size-1]);
}