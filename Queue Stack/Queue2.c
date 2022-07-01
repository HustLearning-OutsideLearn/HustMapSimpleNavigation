#include <stdio.h>
#define MAX 100

struct Queue{
    int value[MAX];
    int front;
    int rear;
};

void insert(struct Queue *S, int value){
    S->value[S->rear] = value;
    S->rear++;
}

int rem(struct Queue * S)
{
    if(S->rear > S->front){
        S->front++;
    }else{
        S->rear = S->front = -1;
    }
}

void init(struct Queue *S){
    S->front = 0;
    S->rear = 0;
}

void main(){
    struct Queue S;
    init(&S);
    for(int i = 1; i<=5; i++){
        insert(&S, i);
    }
    for(int i = S.front; i < S.rear; i++){
        printf("%d ", S.value[i]);
    }
    rem(&S);
    printf("\n");
    for(int i = S.front; i < S.rear; i++){
        printf("%d ", S.value[i]);
    }
}