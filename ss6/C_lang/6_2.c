#include <stdio.h>

int p(int index, int key, const int* array){
    if(array[index] >= key) return 1; 
    else return 0;
}

int bin_search(int key, const int* array, int size){
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
    int array[] = {1, 3, 4, 20, 22, 23, 30, 40};

    printf("p(%d, %d, array) = %d\n", 3, 30, p(3, 30, array));
    printf("p(%d, %d, array) = %d\n",1, 30, p(1, 30, array));
    printf("p(%d, %d, array) = %d\n", 4, 4, p(4, 4, array));

    printf("bin_search(20,array, 8) = %d\n"
            ,bin_search(20, array, 8) );
    printf("bin_search(30,array, 8) = %d\n"
            ,bin_search(30, array, 8));
    printf("bin_search(22,array, 8) = %d\n"
            ,bin_search(22, array, 8));
    printf("bin_search(23, array, 8) = %d\n"
            ,bin_search(23, array, 8));
}
