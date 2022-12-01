#include <stdio.h>

int sum_N(int N){
    if(N == 0)return 0;
    return N + sum_N(N - 1);
}

int main(void){
    int res = sum_N(3);
    printf("res = %d\n", res);
    res = sum_N(4);
    printf("res = %d\n", res);
}
