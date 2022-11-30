#include <stdio.h>

int search_min(int* array, int size){
    int min = 114514;
    int index_min = 0;
    for(int i = 0; i < size; ++i){
        if(array[i] < min){
            min = array[i];
            index_min = i;
        }
    }
    return index_min;
}

int main(void){
    int array[] = {10,31,5,17,1,11,5};

    int index_min = search_min(array,7);
    printf("index_min = %d\n",index_min);
    printf("min of array = %d\n",array[index_min]);
}
