#include <stdio.h>

int GCD(int m ,int n){
    if(n == 0) return m;
    return GCD(n,m % n);
}

int main(void){
    int res_0 = GCD(15,10);
    printf("res_0 = %d\n",res_0);
    int res_1 = GCD(30,60);
    printf("res_1 = %d\n",res_1);
}
