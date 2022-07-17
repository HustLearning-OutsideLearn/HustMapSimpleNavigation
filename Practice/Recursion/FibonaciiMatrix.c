#include <stdio.h>

void multiply(int A[2][2], int B[2][2]){
    int x = A[0][0]*B[0][0] + A[1][1]*B[1][0];
    int y = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    int z = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    int q = A[1][0]*B[0][1] + A[1][1]*B[1][1];

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = q;
}
void power(int arr[2][2], int n){
    if(n == 0 || n == 1){
        return;
    }
    int M[2][2] = {{1, 1}, {1, 0}};
    power(arr, n/2);
    multiply(arr, arr);
    if(n%2 != 0){
        multiply(arr, M);
    }
}
int fibo(int n){
    if(n == 0){
        return n;
    }else{
        int F[2][2] = {{1, 1}, {1, 0}};
        power(F, n-1);
        return F[0][0];
    }
}

void main(){
    int n = 9;
    printf("The %dth number of fibo series is: %d", n, fibo(n));
}