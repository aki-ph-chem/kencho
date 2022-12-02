#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 

// 区間を表現する構造体
struct Interval{
    int left, right;
};

// Intervalのコンストラクタ
void init_interval(struct Interval* obj, int left, int right){
    obj->left = left, obj->right = right;
}

// rightの値の比較
int cmp_interval(const void* A, const void* B){
    int right_A = ((struct Interval*)A)->right;
    int right_B = ((struct Interval*)B)->right;
    return right_A - right_B;
}

// Intervalの配列の中身をprint
void show_interval(const struct Interval* obj, int size){
    for(int i = 0; i < size; ++i){
        printf("left = %d, right = %d\n", obj[i].left, obj[i].right);
    }
}

int main(void){
    int left[SIZE] = {0, 2, 4, 4, 8};
    int right[SIZE] = {3, 5, 7, 5, 10};

    struct Interval interval[SIZE];
    for(int i = 0; i < (int)SIZE; ++i){
        init_interval(&interval[i], left[i], right[i]);
    }
    // sort
    qsort(interval, SIZE, sizeof(struct Interval), cmp_interval);
    // 貪欲法
    struct Interval p = {0,0};
    int num_interval = 0;
    for(int i = 0; i < SIZE; ++i){
        if(p.right > interval[i].left) continue;
            p = interval[i];
            ++num_interval;
    }
    printf("num_interval = %d", num_interval);
}
