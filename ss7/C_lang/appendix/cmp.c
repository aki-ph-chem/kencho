#include <stdio.h>
#include <stdlib.h>

// ただvoid*をint*にキャストしてからデリファレンスして引き算してreturnしているだけ

int cmp(const void* a, const void* b){
    return(*(int*)a - *(int*)b);
}

int main(void){
    int a = 100, b = 10;
    int res_0 = cmp(&a, &b);
    printf("res_0 = %d\n",res_0);

    int res_1 = cmp(&b, &a);
    printf("res_1 = %d\n",res_1);
}

