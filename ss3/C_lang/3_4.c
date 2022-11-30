#include <stdio.h>

int search_min(int* array_a, int* array_b, int size, int K){
    int min = 114514;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(array_a[i] + array_b[j] < K){
                continue;
            }else if(array_a[i] + array_b[j] < min){
                min = array_a[i] + array_b[j];
            }
        }
    }
    return min;
}

int main(void){
    int A[] = {1,2,3,4,5};
    int B[] = {2,4,6,8,10};
    int res = search_min(A, B, 5, 10);
    printf("res = %d",res);
}
