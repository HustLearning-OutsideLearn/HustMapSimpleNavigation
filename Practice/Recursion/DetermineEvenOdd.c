#include <stdio.h>

float num(float n){
    if(n == 0){
        return n;
    }else if(n == 1.0){
        return 10.0;
    }else if(n != 1.0){
        return 11.0;
    }else{
        return num(n/2);
    }
}

void main(){
    int n = 11;
    if(num(n) == 10.0){
        printf("EVEN");
    }else if(num(n) == 11.0){
        printf("ODD");
    }
}