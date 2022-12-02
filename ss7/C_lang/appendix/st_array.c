#include <stdio.h>
#include <stdlib.h>

struct Hoge{
    int x,y;
};

void init_hoge(struct Hoge* hoge, int x, int y){
    hoge->x = x, hoge->y = y;
}

void print_hoge(const struct Hoge* hoge, size_t size){
    for(size_t i = 0; i < size; ++i){
        printf("hoge[%zu]: x = %d, y = %d\n", i, hoge[i].x, hoge[i].y);
    }
}

int main(void){
    int X[] = {1, 2, 3, 4, 5};
    int Y[] = {2, 4, 6, 8, 10};

    struct Hoge h_0[5];
    for(size_t i = 0; i < 5; ++i){
        init_hoge(&h_0[i], X[i], Y[i]);
    }
    print_hoge(h_0, 5);
}
