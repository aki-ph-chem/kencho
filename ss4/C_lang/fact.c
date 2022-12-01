#include <stdio.h>

long long fact(long long N){
    printf("call fact(%d)\n",N);
    if(N == 0)return 1;
    long long result = N * fact(N - 1);
    printf("%d! = %d\n", N, result);
    return result;
}

int main(void){
    fact(10);
}
