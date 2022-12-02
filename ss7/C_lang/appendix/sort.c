#include <stdio.h>
#include <stdlib.h>

/*
 in stdlib.h
 void qsort(void* base, size_t n_item, size_t size, int (*compar const void*, const void*))

base: 目的とする配列の先頭のポインタ
n_item: 配列の要素数
size: 配列の型のサイズ
compar: ２個のvoid型のポインタを引数とするint型を返す関数へのポインタ, ２個の値の大小比較に使う

 */ 

int cmp(const void* a, const void* b){
    return(*(int*)a - *(int*)b);
}

int main(void){
    int array[] = {88, 56, 100, 2, 25};

    printf("Before sorting the array is: \n");
    for(size_t i = 0; i < 5; ++i){
        printf("array[%zu] = %d\n",i, array[i]);
    }

    qsort(array, 5, sizeof(int), cmp);
    printf("After sorting the array is: \n");
    for(size_t i = 0; i < 5; ++i){
        printf("array[%zu] = %d\n",i, array[i]);
    }

}
