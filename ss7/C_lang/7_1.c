#include <stdio.h>
#define N_COINS 6

int main(void){
    const int coins[N_COINS] = {500, 100, 50, 10, 5, 1};

    int X = 1755;
    int my_coins[N_COINS] = {5, 3, 3, 3, 3, 3};
    int num_coins = 0;
    for(int i = 0; i < (int)N_COINS; ++i){
        int a = X/coins[i];
        if(my_coins[i] >= a){
            num_coins += a;
        }else{
            num_coins += my_coins[i];
        }

        X -= a * coins[i];
    }
    printf("num_coins = %d",num_coins);
}
