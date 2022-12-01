#include <stdio.h>

int sum(int N){
    printf("call sum(%d)\n ",N);
    if(N == 0)return 0;

    int result = N + sum(N - 1);
    printf("sum up to %d: %d\n", N, result);
    return result;
}

int main(void){
    sum(10);
}
