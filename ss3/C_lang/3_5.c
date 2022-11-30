#include <stdio.h>

int bit_search(int* array,int size, int W){
    int flag = 0;
    for(int i = 0; i < 1<<size; ++i){
        int sum = 0;
        for(int j = 0; j < size; ++j){
            if(i & 1<<j) sum +=  array[j];
        }
        if(W == sum){
            flag = 1;
        }
    }
    return flag;
}

int main(void){
    int array[] = {1,2,3,4};
    int res = bit_search(array,4,1);
    res = bit_search(array,4,2);
    res = bit_search(array,4,3);
    res = bit_search(array,4,4);

    if(res){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

}
