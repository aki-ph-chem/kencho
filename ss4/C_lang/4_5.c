#include<stdio.h>

int search(int* array, int size, int n, int W){
    if(n == 0){
        if(W == 0){
            return 1;
        }else{
            return 0;
        }
    }
    // a[i]を選ばない
    if(search(array, size, n - 1, W))return 1;
    // a[i]を選ぶ
    if(search(array, size, n - 1, W - array[n - 1])) return 1;

    return 0;
} 

int main(void){
    int array[] = {1,2,3,4};
    int res =search(array, 4, 4, 1);
    res =search(array, 4, 4, 2);
    res =search(array, 4, 4, 7);
    res =search(array, 4, 4, 9);
    res =search(array, 4, 4, 19);

    if(res){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}
