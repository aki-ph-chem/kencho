#include <stdio.h>
#include <stdlib.h>

#define N 1024
int array[(size_t)N];

long long fib(long long n){

    if(n == 0)return 0;
    else if(n == 1)return 1;

    if(array[n] != -1)return array[n];

    return array[n] = fib(n - 1) + fib(n - 2);
}

int main(void){
    for(long long i = 0; i < N; ++i){
        array[i] = -1;
    }

    int res = fib(0);
    printf("res = %d\n",res);
    res = fib(1);
    printf("res = %d\n",res);
    res = fib(2);
    printf("res = %d\n",res);
    res = fib(6);
    printf("res = %d\n",res);
}
