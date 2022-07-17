#include <stdio.h>

int even();
int odd();

int even(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    else return odd(n-1);
}

int odd(int n){
    if(n == 1) return 0;
    if(n == 0) return 1;
    else return odd(n-1);
}