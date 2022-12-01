#include <stdio.h>

int fib(int n){
    int x_k0 =  0, x_k1 =1;
    if(n == 0)return x_k0;
    if(n == 1)return x_k1;

    int res = 0;
    for(int i = 2 ; i <= n; ++i){
        res = x_k0 + x_k1;
        x_k0 = x_k1;
        x_k1 = res; 
    }
    return res;
}

int main(void){
    int res_0 =  fib(6);
    printf("res_0 = %d\n",res_0);

}
