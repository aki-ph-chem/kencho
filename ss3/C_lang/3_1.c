#include <stdio.h>

int lenear_search(int* array, int size, int key){
    int is_exist = 0;
    for(int i = 0; i < size; ++i){
        if(array[i] == key){
            is_exist = 1;
        }
    }
    return is_exist;
}

int main(void){
    int array[] = {1,3,5,7,10,11,100};

    int res = lenear_search(array, 7,3);
    if(res){
        printf("exist\n");
    }else{
        printf("not exist\n");
    }

    res = lenear_search(array, 7,114514);
    if(res){
        printf("exist\n");
    }else{
        printf("not exist\n");
    }
}
