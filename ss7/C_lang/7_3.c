#include <stdio.h>
#define N 5

int main(void){
    long long array_a[N] = {3,5,7,2,10};
    long long array_b[N] = {8,15,6,3,11};

    long long sum_of_push = 0;
    for(int i = N - 1; i >= 0; --i){
        long long r = (array_a[i] + sum_of_push) % array_b[i];
        if(r != 0){
            sum_of_push += array_b[i] - r;
        }
    }
    printf("sum_of_push = %d\n",sum_of_push);
}
