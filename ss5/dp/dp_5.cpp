#include <iostream>
#define N 4

int v[N] = {2, 1, 3, 2};
int w[N] = {3, 2, 4, 2};

// 良くない全探索の書き方: 引数が多いと動的計画に持って行きにくくなる
// そこまで選んだ品物の価値の和 vsumを追加
int search(int i, int u, int vsum){
    int n = N;
    if(i == n){
        return vsum;
    }else if(u < w[i]){
        return search(i + 1, u, vsum);
    }else{
        int res_1 = search(i + 1, u, vsum);
        int res_2 = search(i + 1, u - w[i], vsum + v[i]);
        return std::max(res_1, res_2);
    }
}

int main(void){
    std::cout << search(0,10,0) << std::endl;
}
