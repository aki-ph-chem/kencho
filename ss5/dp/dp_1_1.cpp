#include <iostream>
#define N 4

int v[N] = {2, 1, 3, 2};
int w[N] = {3, 2, 4, 2};

int search(int i, int u){
    int n = N;
    if(i == n){
        return 0;
    }else if(u < w[i]){
        return search(i + 1, u);
    }else{
        int res_1 = search(i + 1, u);
        int res_2 = search(i + 1, u - w[i]) + v[i];
        return std::max(res_1, res_2);
    }
}

int main(void){
    std::cout << search(0,10) << std::endl;
}
