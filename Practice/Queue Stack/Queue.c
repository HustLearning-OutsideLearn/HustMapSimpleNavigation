#include <stdio.h>
#define MAX 100

struct Queue{
    int value[MAX];
    int size;
};

void insert(struct Queue *S, int value){
    S->value[S->size] = value;
    S->size++;
}

int rem(struct Queue * S)
{
    for(int i = 0; i <= S->size; i++){
        S->value[i] = S->value[i+1];
    }
    S->size--;
}

void init(struct Queue *S){
    S->size = 0;
}

void main(){
    struct Queue S;
    init(&S);
    for(int i = 1; i<=5; i++){
        insert(&S, i);
    }
    for(int i = 0; i < S.size; i++){
        printf("%d ", S.value[i]);
    }
    rem(&S);
    printf("\n");
    for(int i = 0; i < S.size; i++){
        printf("%d ", S.value[i]);
    }
}