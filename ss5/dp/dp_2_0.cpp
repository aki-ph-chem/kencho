#include <iostream>
#define MAX_N 11 
#define MAX_U 11
#define SIZE 4

// 方法1: メモ化再帰
// メモ用の配列
bool done[MAX_N][MAX_U + 1];
int memo[MAX_N][MAX_U + 1];

// 対象の配列
int v[SIZE] = {2, 1, 3, 2};
int w[SIZE] = {3, 2, 4, 2};

// メモしながら探索する
int search(int i, int u){
    int n = SIZE;
    if(done[i][u]){
        return memo[i][u];
    }else if(i == n){
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
    // 配列の初期化
    for(std::size_t i = 0; i < MAX_N; ++i){
        for(std::size_t j = 0; j < MAX_U; ++j){
            done[i][j] = false;
            memo[i][j] = 0;
        }
    }
    std::cout << search(0,10) << std::endl;
}

