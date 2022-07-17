#include <stdio.h>

int fibonaci(int n){
    if(n == 0 || n == 1){
        return n;
    }else{
        return fibonaci(n-1) + fibonaci(n-2);
    }
}
void main(){
    int n = 9;
    printf("The number %dth of Fibonacii Series: %d", n, fibonaci(n));
}

