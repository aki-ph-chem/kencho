#include <stdio.h>

int lenear_search(int* array, int size, int key){
    int right = 0, left = size;
    for(int i = 0; i < size; ++i){
        if(array[i] == key){
            return i;
        }
    }
    return -1;
}

int main(void){
    int array[] = {1,3,5,7,10,11,100};

    printf("res = %d\n", lenear_search(array, 7, 3));
    printf("res = %d\n", lenear_search(array, 7, 5));
    printf("res = %d\n", lenear_search(array, 7, 50));

}
