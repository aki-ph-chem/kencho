#include <stdio.h>
#include <stdlib.h>
#define N 3

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int p(int index, int key, const int* array){
    if(array[index] >= key)return 1;
    else return 0;
}

int bin_search(int key, const int*array, int size){
    int left = 0, right = size;
    while(right - left > 1){
        int mid = left + (right - left)/2;
        if(p(mid, key, array)){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int main(void){
    const int INF = 20000;
    int array_a[N] = {8,5,4}; 
    int array_b[N] = {4,1,9};
    int K = 10; 

    qsort(array_b, N, sizeof(int), cmp);
    int min_value = INF; 
    for(int i = 0; i < N; ++i){
        int index = bin_search(K - array_a[i], array_b, N); 
        int val = array_b[index];

        if(array_a[i] + val < min_value){
            min_value = array_a[i] + val;
        }
    }
    printf("min_value  = %d\n", min_value);
}
