#include <stdio.h>
#define MAX 100

struct Stack{
    int value[MAX];
    int size;
};

void insert(struct Stack *S, int value){
    S->value[S->size] = value;
    S->size++;
}

int rem(struct Stack * S)
{
    S->size--;
}

void init(struct Stack *S){
    S->size = 0;
}

void main(){
    struct Stack S;
    init(&S);
    insert(&S, 10);
    printf("Value get: %d", S.value[S.size-1]);
    rem(&S);
    printf("Value get after remove: %d", S.value[S.size-1]);
}