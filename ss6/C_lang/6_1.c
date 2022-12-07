#include <stdio.h>

int bin_search(const int* array,int size, int key){
    int left = 0, right = size - 1;
    while(right >= left) {
        int mid = left + (right - left)/2;
        if(array[mid] == key) return mid;
        else if(array[mid] > key) right = mid - 1;
        else if(array[mid] < key) left = mid + 1;
    }
    return -1;
}

int main(void){
    const int array[] = {3,5,8,10,14,17,21,39};

    printf("i = %d\n", bin_search(array,8,8));
    printf("i = %d\n", bin_search(array,8,3));
    printf("i = %d\n", bin_search(array,8,39));
}
