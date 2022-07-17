#include <stdio.h>

int find(int arr[], int n){
    if(n == 0){
        return arr[n];
    }else{
        return find(arr, n-1);
    }
}
void main(){
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13};
    int n = 8;
    printf("The first number is: %d", find(arr, n - 1));
}